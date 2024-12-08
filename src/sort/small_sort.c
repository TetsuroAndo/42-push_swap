/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:37:16 by teando            #+#    #+#             */
/*   Updated: 2024/12/09 00:08:01 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** 3要素ソート最適解:
** パターンは以下 (Aスタックtopが左)
** (1) a < b < c : 完全整列済み -> 何もしない
** (2) a < c < b : rra + sa
** (3) b < a < c : sa
** (4) b < c < a : ra
** (5) c < a < b : rra
** (6) c < b < a : sa + rra
*/
static void	three_sort(t_stacks *st)
{
	int	a;
	int	b;
	int	c;

	a = st->data[0];
	b = st->data[1];
	c = st->data[2];
	if (a < b && b < c)
		return ;
	else if (a < c && c < b)
	{
		execute_operation(st, OP_RRA);
		execute_operation(st, OP_SA);
	}
	else if (b < a && a < c)
		execute_operation(st, OP_SA);
	else if (b < c && c < a)
		execute_operation(st, OP_RA);
	else if (c < a && a < b)
		execute_operation(st, OP_RRA);
	else if (c < b && b < a)
	{
		execute_operation(st, OP_SA);
		execute_operation(st, OP_RRA);
	}
}

/*
** 2要素ソート
*/
void	small_sort_a(t_stacks *st, int size)
{
	if (size <= 1)
		return ;
	if (size == 2 && st->data[0] > st->data[1])
		execute_operation(st, OP_SA);
	else if (size == 3)
		three_sort(st);
}

/*
** スタックA中の最小値のインデックスを取得
*/
static int	get_min_index(t_stacks *st)
{
	int	i;
	int	min_val;
	int	min_idx;

	min_idx = 0;
	min_val = st->data[0];
	i = 0;
	while (++i < st->a_size)
	{
		if (st->data[i] < min_val)
		{
			min_val = st->data[i];
			min_idx = i;
		}
	}
	return (min_idx);
}

/*
** 最小要素をトップへ持ってきてpbでBへ送る
** 回転方向は最短手数で移動するよう選択する
*/
static void	move_min_to_b(t_stacks *st)
{
	int	min_idx;
	int	half;

	min_idx = get_min_index(st);
	half = st->a_size / 2;
	if (min_idx <= half)
	{
		while (min_idx-- > 0)
			execute_operation(st, OP_RA);
	}
	else
	{
		while (min_idx++ < st->a_size)
			execute_operation(st, OP_RRA);
	}
	execute_operation(st, OP_PB);
}

/*
** 5要素または4要素ソート:
** 1. 最小要素をBへ
** 2. 再度最小要素をBへ(この時点でBには2つの最小要素が積まれている)
** 3. 必要ならBでsbして2つが昇順になるよう調整
** 4. 残り3要素をthree_sortで整列
** 5. pa paで戻し、完全整列
*/
void	five_sort(t_stacks *st)
{
	while (st->a_size > 3)
		move_min_to_b(st);
	if (st->b_size == 2 && st->data[st->total_size
		- 2] < st->data[st->total_size - 1])
		execute_operation(st, OP_SB);
	three_sort(st);
	while (st->b_size > 0)
		execute_operation(st, OP_PA);
}
