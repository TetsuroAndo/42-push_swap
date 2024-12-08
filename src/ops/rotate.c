/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:09:07 by teando            #+#    #+#             */
/*   Updated: 2024/12/08 23:42:07 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Aを1回回転 (ra)
*/
void	rotate_a(t_stacks *st)
{
	int	b_top;
	int	tmp;
	int	i;

	if (st->a_size <= 1)
		print_error(": Cannot rotate. A stack is empty");
	b_top = st->total_size - 1;
	tmp = st->data[0];
	i = 0;
	while (i < st->a_size - 1)
	{
		st->data[i] = st->data[i + 1];
		++i;
	}
	st->data[st->a_size - 1] = tmp;
}

/*
** Bを1回回転 (rb)
*/
void	rotate_b(t_stacks *st)
{
	int	b_end;
	int	b_top;
	int	tmp;
	int	i;

	if (st->b_size <= 1)
		print_error(": Cannot rotate. B stack is empty");
	b_end = st->total_size - st->b_size;
	b_top = st->total_size - 1;
	tmp = st->data[b_top];
	i = b_top;
	while (i > b_end)
	{
		st->data[i] = st->data[i - 1];
		--i;
	}
	st->data[b_end] = tmp;
}
