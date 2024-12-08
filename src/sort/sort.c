/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:37:49 by teando            #+#    #+#             */
/*   Updated: 2024/12/09 04:16:21 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief 与えられた配列をバブルソートでソート(単純化のため)
 */
static void	simple_sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

/**
 * @brief スタックAのデータをもとにソート済み配列を作成
 */
static int	*create_sorted_array(t_stacks *st)
{
	int	*sorted;

	sorted = (int *)malloc(sizeof(int) * st->a_size);
	if (!sorted)
		print_error(": malloc failed in create_sorted_array");
	ft_memcpy(sorted, st->data, sizeof(int) * st->a_size);
	simple_sort_array(sorted, st->a_size);
	return (sorted);
}

/**
 * @brief タークソートで使用するチャンク数を決定する。
 * ここでは要素数に応じて適当にチャンク数を決める。
 * 例:
 * size <= 100なら4チャンク、
 * size <= 500なら8チャンク、
 * それ以上は適宜増やす、など。
 */
static int	get_chunk_count(int size)
{
	if (size <= 100)
		return (4);
	else if (size <= 500)
		return (8);
	else
		return (size / 60); // 適当な分割例
}

/**
 * @brief 指定したチャンクの範囲にある要素をBへ移動する。
 * チャンク境界： sorted配列の start_idx ~ end_idx の値をBへ
 */
static void	push_chunk_to_b(t_stacks *st, int *sorted, int start_idx,
		int end_idx)
{
	int	min_val;
	int	max_val;
	int	needed;
	int	pushed;

	min_val = sorted[start_idx];
	max_val = sorted[end_idx];
	needed = (end_idx - start_idx + 1);
	pushed = 0;
	while (pushed < needed)
	{
		if (st->data[0] >= min_val && st->data[0] <= max_val)
		{
			execute_operation(st, OP_PB);
			pushed++;
		}
		else
			execute_operation(st, OP_RA);
	}
}

/**
 * @brief スタックBからAへ最大値から順に戻していく関数
 * Bにはpush_chunk_to_bで段階的に低い値が下に行くように入っているので
 * BからAへは大きい値から順に戻せばよい。
 */
static void	push_back_to_a(t_stacks *st)
{
	int	max_val;
	int	max_idx;
	int	j;
	int	val;

	while (st->b_size > 0)
	{
		// Bの中で最大値の位置を検索
		max_val = INT_MIN;
		max_idx = 0;
		j = 0;
		while (j < st->b_size)
		{
			val = st->data[st->total_size - 1 - j];
			if (val > max_val)
			{
				max_val = val;
				max_idx = j;
			}
			j++;
		}
		// max_idxをスタックトップへ持ってくる
		if (max_idx <= st->b_size / 2)
			while (max_idx-- > 0) // 上半分にあるならRBで上に持ってくる
				execute_operation(st, OP_RB);
		else
			while (max_idx++ < st->b_size) // 下半分にあるならRRBで上に持ってくる
				execute_operation(st, OP_RRB);
		// 最大値をAへ戻す
		execute_operation(st, OP_PA);
	}
}

/**
 * @brief タークソートのメイン部分
 * 1. スタックAの要素をソートした配列を用意
 * 2. チャンク境界を決め、チャンクごとにAからBへ該当要素を移動
 * 3. 全部Bへ移動完了後、BからAへ要素を戻し、最終的に整列状態にする
 */
static void	turk_sort(t_stacks *st)
{
	int	*sorted;
	int	chunk_count;
	int	chunk_size;
	int	i;
	int	start_idx;
	int	end_idx;

	sorted = create_sorted_array(st);
	chunk_count = get_chunk_count(st->a_size) + 1;
	chunk_size = st->a_size / chunk_count;
	// チャンクごとにAからBへ
	i = 0;
	while (i < chunk_count)
	{
		start_idx = i * chunk_size;
		end_idx = start_idx + chunk_size - 1;
		if (i == chunk_count - 1)
			end_idx = st->a_size - 1;
		push_chunk_to_b(st, sorted, start_idx, end_idx);
		i++;
	}
	// BからAへ戻す (最大値から順に戻す)
	push_back_to_a(st);
	free(sorted);
}

/**
 * @brief メインのsort_stack関数
 * 要素数に応じてsmall_sortまたはタークソートを適用する
 */
void	sort_stack(t_stacks *st)
{
	if (is_sorted(st))
		return ;
	if (st->a_size <= 3)
		three_sort(st);
	else if (st->a_size <= 5)
		five_sort(st);
	else
		turk_sort(st);
}
