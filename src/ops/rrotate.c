/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:09:32 by teando            #+#    #+#             */
/*   Updated: 2024/12/09 03:30:59 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_a(t_stacks *st)
{
	int	tmp;

	if (st->a_size <= 1)
		print_error(": Cannot rrotate. A stack is empty");
	tmp = st->data[st->a_size - 1];
	ft_memmove(&st->data[1], &st->data[0], (st->a_size - 1) * sizeof(int));
	st->data[0] = tmp;
}

void	rrotate_b(t_stacks *st)
{
	int	b_end;
	int	b_top;
	int	tmp;

	if (st->b_size <= 1)
		print_error(": Cannot rrotate. B stack is empty");
	b_end = st->total_size - st->b_size;
	b_top = st->total_size - 1;
	tmp = st->data[b_end];
	ft_memmove(&st->data[b_end], &st->data[b_end + 1], (st->b_size - 1)
		* sizeof(int));
	st->data[b_top] = tmp;
}
