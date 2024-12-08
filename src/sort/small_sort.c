/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:37:16 by teando            #+#    #+#             */
/*   Updated: 2024/12/09 08:29:06 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_stacks *st)
{
	if (st->a_size < 2)
		return ;
	if (st->data[0] > st->data[1])
		execute_operation(st, OP_SA);
	if (st->a_size == 3 && st->data[1] > st->data[2])
	{
		execute_operation(st, OP_RRA);
		if (st->data[0] > st->data[1])
			execute_operation(st, OP_SA);
	}
}

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

static void	move_min_to_b(t_stacks *st)
{
	int	min_idx;

	min_idx = get_min_index(st);
	while (min_idx > 0 && min_idx <= st->a_size / 2)
	{
		execute_operation(st, OP_RA);
		min_idx--;
	}
	while (min_idx > 0 && min_idx > st->a_size / 2)
	{
		execute_operation(st, OP_RRA);
		if (min_idx == st->a_size - 1)
			min_idx = 0;
		else
			min_idx++;
	}
	execute_operation(st, OP_PB);
}

void	five_sort(t_stacks *st)
{
	while (st->a_size > 3)
		move_min_to_b(st);
	three_sort(st);
	while (st->b_size > 0)
		execute_operation(st, OP_PA);
}
