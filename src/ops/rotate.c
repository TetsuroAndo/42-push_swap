/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:09:07 by teando            #+#    #+#             */
/*   Updated: 2024/12/07 22:22:24 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Aを1回回転 (ra)
*/
void	rotate_a(t_stacks *st)
{
	int	tmp;
	int	i;

	if (st->a_size > 1)
	{
		tmp = st->data[0];
		i = 0;
		while (i < st->a_size - 1)
		{
			st->data[i] = st->data[i + 1];
			i++;
		}
		st->data[st->a_size - 1] = tmp;
	}
}

/*
** Bを1回回転 (rb)
*/
void	rotate_b(t_stacks *st)
{
	int	top_idx;
	int	tmp;
	int	i;

	if (st->b_size > 1)
	{
		top_idx = st->total_size - 1;
		tmp = st->data[top_idx];
		i = 0;
		while (i < st->b_size - 1)
		{
			st->data[top_idx - i] = st->data[top_idx - i - 1];
			i++;
		}
		st->data[top_idx - (st->b_size - 1)] = tmp;
	}
}
