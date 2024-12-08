/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:09:07 by teando            #+#    #+#             */
/*   Updated: 2024/12/09 03:31:04 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stacks *st)
{
	int	tmp;

	if (st->a_size <= 1)
		print_error(": Cannot rotate. A stack is empty");
	tmp = st->data[0];
	ft_memmove(&st->data[0], &st->data[1], (st->a_size - 1) * sizeof(int));
	st->data[st->a_size - 1] = tmp;
}

void	rotate_b(t_stacks *st)
{
	int	b_end;
	int	b_top;
	int	tmp;

	if (st->b_size <= 1)
		print_error(": Cannot rotate. B stack is empty");
	b_end = st->total_size - st->b_size;
	b_top = st->total_size - 1;
	tmp = st->data[b_top];
	ft_memmove(&st->data[b_end + 1], &st->data[b_end], (st->b_size - 1)
		* sizeof(int));
	st->data[b_end] = tmp;
}
