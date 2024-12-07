/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:37:49 by teando            #+#    #+#             */
/*   Updated: 2024/12/08 01:13:50 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	quicksort_like(t_stacks *st, const int size)
{
	int	p1;
	int	p2;
	int	pushed_small;
	int	pushed_large;
	int	rotated;
	int	val;
	int	i;

	// 以下、大規模ソート用の処理 (ピボットによる分割)
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
	// 中間グループはすでに A に残っている
	quicksort_like(st, size - pushed_small - pushed_large);
}

void	sort_stack(t_stacks *st)
{
	const int	size = st->a_size;

	if (size <= 3)
		small_sort_a(st, size);
	else if (size <= 5)
		five_sort(st);
	else
		quicksort_like(st, size);
}
