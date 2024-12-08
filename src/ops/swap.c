/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:08:34 by teando            #+#    #+#             */
/*   Updated: 2024/12/09 01:06:42 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void	swap_a(t_stacks *st)
{
	if (st->a_size <= 1)
		print_error(": Cannot swap. A stack is empty");
	swap_top(&st->data[0], &st->data[1]);
}

void	swap_b(t_stacks *st)
{
	int	b_top;

	if (st->b_size <= 1)
		print_error(": Cannot swap. B stack is empty");
	b_top = st->total_size - 1;
	swap_top(&st->data[b_top], &st->data[b_top - 1]);
}
