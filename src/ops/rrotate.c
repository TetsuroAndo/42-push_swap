/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:09:32 by teando            #+#    #+#             */
/*   Updated: 2024/12/07 22:19:55 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Aを逆回転 (rra)
*/
void	rrotate_a(t_stacks *st)
{
	int	tmp;
	int	i;

	
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
void	rrotate_b(t_stacks *st)
{
	int	top_idx;
	int	bottom_idx;
	int	tmp;
	int	i;

	
	if (st->b_size > 1)
	{
		top_idx = st->total_size - 1;
		bottom_idx = top_idx - (st->b_size - 1);
		tmp = st->data[bottom_idx];
		i = bottom_idx;
		while (i < top_idx)
		{
			st->data[i] = st->data[i + 1];
			i++;
		}
		st->data[top_idx] = tmp;
	}
}
