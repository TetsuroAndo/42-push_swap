/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:08:12 by teando            #+#    #+#             */
/*   Updated: 2024/12/07 22:19:47 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** BのtopをAへプッシュ
*/
void	push_a(t_stacks *st)
{
	int	b_top;
	int	i;

	if (st->b_size < 1)
		return ;
	b_top = st->total_size - 1;
	i = st->a_size;
	while (i > 0)
	{
		st->data[i] = st->data[i - 1];
		i--;
	}
	st->data[0] = st->data[b_top];
	st->b_size--;
	st->data[b_top] = 0;
	st->a_size++;
}

/*
** AのtopをBへプッシュ
*/
void	push_b(t_stacks *st)
{
	int	b_top;
	int	i;

	if (st->a_size < 1)
		return ;
	b_top = st->total_size - 1 - st->b_size;
	st->data[b_top] = st->data[0];
	i = 0;
	while (i < st->a_size - 1)
	{
		st->data[i] = st->data[i + 1];
		i++;
	}
	st->a_size--;
	st->b_size++;
	st->data[st->a_size] = 0;
}
