/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:08:12 by teando            #+#    #+#             */
/*   Updated: 2024/12/09 08:29:06 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_btoa(t_stacks *st)
{
	int	b_top;
	int	tmp;

	if (st->b_size == 0)
		print_error(": Cannot push. B stack is empty");
	b_top = st->total_size - 1;
	tmp = st->data[b_top];
	ft_memmove(&st->data[1], &st->data[0], (st->total_size - 1) * sizeof(int));
	st->data[0] = tmp;
	st->a_size += 1;
	st->b_size -= 1;
}

void	push_atob(t_stacks *st)
{
	int	b_top;
	int	tmp;

	if (st->a_size == 0)
		print_error(": Cannot push. A stack is empty");
	b_top = st->total_size - 1;
	tmp = st->data[0];
	ft_memmove(&st->data[0], &st->data[1], (st->total_size - 1) * sizeof(int));
	st->data[b_top] = tmp;
	st->a_size -= 1;
	st->b_size += 1;
}
