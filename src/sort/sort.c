/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:37:49 by teando            #+#    #+#             */
/*   Updated: 2024/12/08 00:43:49 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			g_best_moves = INT_MAX;
static t_operation g_best_solution[5000]; // 十分大きな配列を確保、操作列格納用

static t_operation	g_ops[] = {OP_SA, OP_SB, OP_SS, OP_PA, OP_PB, OP_RA, OP_RB,
		OP_RR, OP_RRA, OP_RRB, OP_RRR};

/*
** スタック状態がソート済みかチェック
*/
static int	is_sorted_stack(t_stacks *st)
{
	for (int i = 0; i < st->a_size - 1; i++)
	{
		if (st->data[i] > st->data[i + 1])
			return (0);
	}
	// Bスタックは空である必要がある
	if (st->b_size != 0)
		return (0);
	return (1);
}

/*
** 現在の操作列が最短解より短いか、あるいは解に到達した場合に記録
*/
static void	save_solution_if_better(t_operation *ops, int depth)
{
	if (depth < g_best_moves)
	{
		g_best_moves = depth;
		for (int i = 0; i < depth; i++)
			g_best_solution[i] = ops[i];
	}
}

/*
** 全探索用の再帰関数
** depth: 現在の深さ
** ops: これまでに実行した操作の列
** st: 現在のスタック状態
*/
static void	full_search_dfs(int depth, t_operation *ops, t_stacks *st)
{
	t_stacks	backup;
	int			*data_backup;

	if (depth >= g_best_moves || depth > MAX_DEPTH) // 現在の最短解を上回ったら打ち切り
		return ;
	if (is_sorted_stack(st))
	{
		save_solution_if_better(ops, depth);
		return ;
	}
	// 深さ優先で全ての操作を試す
	for (int i = 0; i < (int)(sizeof(g_ops) / sizeof(t_operation)); i++)
	{
		backup = *st;
		data_backup = __builtin_alloca(sizeof(int) * st->total_size);
		ft_memcpy(data_backup, st->data, sizeof(int) * st->total_size);
		backup.data = data_backup;
		// 操作を実行
		// SS, RR, RRRなど複合操作はexecute_operation内で2回動かしているため注意
		// 単純化のため直接対応する操作関数を呼んだ後、条件分岐してstdoutに出さずopsに記録のみ行う
		// → ここではexecute_operationではなく同様の処理をコピー、またはexecute_operationを出力しない関数に書き換えが必要
		// 簡易化のためexecute_operationを直接利用せず、操作関数呼び出し＋op_str表示を分離する必要あり。
		// ここでは実行関数を直接呼び出す例を示す。
		// 操作実行用関数テーブル（ss, rr, rrrは複合扱いなので工夫が必要）
		static void (*op_func_single[])(t_stacks *) = {swap_a, swap_b, NULL,
			push_a, push_b, rotate_a, rotate_b, NULL, rrotate_a, rrotate_b,
			NULL};
		if (g_ops[i] == OP_SS)
		{
			swap_a(&backup);
			swap_b(&backup);
		}
		else if (g_ops[i] == OP_RR)
		{
			rotate_a(&backup);
			rotate_b(&backup);
		}
		else if (g_ops[i] == OP_RRR)
		{
			rrotate_a(&backup);
			rrotate_b(&backup);
		}
		else
			op_func_single[g_ops[i]](&backup);
		// 操作後のスタックで再帰呼び出し
		ops[depth] = g_ops[i];
		full_search_dfs(depth + 1, ops, &backup);
		// backupは自動変数＋allocaなので解放不要
	}
}

static void	full_search(t_stacks *st)
{
	t_operation			ops[5000];
	static const char	*op_str[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
			"rr", "rra", "rrb", "rrr"};

	g_best_moves = INT_MAX;
	full_search_dfs(0, ops, st);
	// g_best_solutionに最適解が入っている
	// 実際に操作を適用してprintする
	for (int i = 0; i < g_best_moves; i++)
	{
		ft_putendl_fd((char *)op_str[g_best_solution[i]], STDOUT_FILENO);
		// 実際にはここでstに再度操作を適用して同期をとる必要があるが、
		// 全探索終了後にprintのみ行う場合は再適用は省略可能
	}
}

void	sort_stack(t_stacks *st)
{
	if (is_sorted(st))
		return ;
	quicksort_like(st, st->a_size);
}

void	quicksort_like(t_stacks *st, int size)
{
	int	p1;
	int	p2;
	int	pushed_small;
	int	pushed_large;
	int	rotated;
	int	val;
	int	i;

	if (size <= 3)
	{
		small_sort_a(st, size);
		return ;
	}
	if (size <= 5)
	{
		full_search(st);
		return ;
	}
	else if (size <= 5)
	{
		five_sort(st);
		return ;
	}
	if (!get_pivots(st, size, &p1, &p2))
		return ;
	pushed_small = 0;
	pushed_large = 0;
	rotated = 0;
	i = 0;
	while (i < size)
	{
		val = st->data[0];
		if (val < p1)
		{
			execute_operation(st, OP_PB);
			pushed_small++;
		}
		else if (val > p2)
		{
			execute_operation(st, OP_PB);
			execute_operation(st, OP_RB);
			pushed_large++;
		}
		else
		{
			execute_operation(st, OP_RA);
			rotated++;
		}
		i++;
	}
	i = 0;
	while (i < rotated)
	{
		execute_operation(st, OP_RRA);
		i++;
	}
	// 大グループを A に戻す
	i = 0;
	while (i < pushed_large)
	{
		execute_operation(st, OP_PA);
		i++;
	}
	quicksort_like(st, pushed_large);
	// 小グループを A に戻す
	i = 0;
	while (i < pushed_small)
	{
		execute_operation(st, OP_PA);
		i++;
	}
	quicksort_like(st, pushed_small);
	// 中間グループは既に A に残っている
	quicksort_like(st, size - pushed_small - pushed_large);
}
