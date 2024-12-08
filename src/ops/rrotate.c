/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:09:32 by teando            #+#    #+#             */
/*   Updated: 2024/12/08 23:42:43 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Aを逆回転 (rra)
*/
void	rrotate_a(t_stacks *st)
{
	int	b_top;
	int	tmp;
	int	i;

	if (st->a_size <= 1)
		print_error(": Cannot rrotate. A stack is empty");
	b_top = st->total_size - 1;
	tmp = st->data[st->a_size - 1];
	i = st->a_size - 1;
	while (i > 0)
	{
		st->data[i] = st->data[i - 1];
		i--;
	}
	st->data[0] = tmp;
}

/*
** Bを逆回転 (rrb)
*/
void	rrotate_b(t_stacks *st)
{
	int	b_end;
	int	b_top;
	int	tmp;
	int	i;

	if (st->b_size <= 1)
		print_error(": Cannot rrotate. B stack is empty");
	b_end = st->total_size - st->b_size;
	b_top = st->total_size - 1;
	tmp = st->data[b_end];
	i = b_end;
	while (i < b_top)
	{
		st->data[i] = st->data[i + 1];
		i++;
	}
	st->data[b_top] = tmp;
}
