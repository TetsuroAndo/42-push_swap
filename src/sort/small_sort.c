/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:37:16 by teando            #+#    #+#             */
/*   Updated: 2024/12/07 22:19:01 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_three_sort(t_stacks *st)
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

void	small_sort_a(t_stacks *st, int size)
{
	if (size <= 1)
		return ;
	if (size == 2 && st->data[0] > st->data[1])
		execute_operation(st, OP_SA);
	else if (size == 3)
		simple_three_sort(st);
	else if (size == 4)
		execute_operation(st, OP_PB);
	else if (size == 5)
		execute_operation(st, OP_PB);
}

void	five_sort(t_stacks *st)
{
	while (st->a_size > 3)
		execute_operation(st, OP_PB);
	simple_three_sort(st);
	while (st->b_size > 0)
	{
		execute_operation(st, OP_PA);
		if (st->data[0] > st->data[1])
			execute_operation(st, OP_SA);
	}
}
