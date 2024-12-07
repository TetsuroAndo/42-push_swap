/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:09:32 by teando            #+#    #+#             */
/*   Updated: 2024/12/08 01:42:52 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

/*
** Aを逆回転 (rra)
*/
void rrotate_a(t_stacks *st)
{
	int tmp;
	int i;

	if (st->a_size > 1)
	{
		tmp = st->data[st->a_size - 1];
		i = st->a_size - 1;
		while (i > 0)
		{
			st->data[i] = st->data[i - 1];
			i--;
		}
		st->data[0] = tmp;
	}
}

/*
** Bを逆回転 (rrb)
*/
void rrotate_b(t_stacks *st)
{
	int start;
	int end;
	int tmp;
	int i;

	if (st->b_size > 1)
	{
		start = st->total_size - st->b_size;
		end = st->total_size - 1;
		tmp = st->data[end];
		i = end;
		while (i > start)
		{
			st->data[i] = st->data[i - 1];
			i--;
		}
		st->data[start] = tmp;
	}
}
