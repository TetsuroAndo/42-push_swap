/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:37:49 by teando            #+#    #+#             */
/*   Updated: 2024/12/07 22:16:38 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
