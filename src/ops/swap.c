/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:08:34 by teando            #+#    #+#             */
/*   Updated: 2024/12/07 22:19:57 by teando           ###   ########.fr       */
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

/*
** Aスタックの先頭2要素スワップ
*/
void	swap_a(t_stacks *st)
{
	if (st->a_size > 1)
		swap_top(&st->data[0], &st->data[1]);
}

/*
** Bスタックの先頭2要素スワップ
*/
void	swap_b(t_stacks *st)
{
	int	top_idx;

	if (st->b_size > 1)
	{
		top_idx = st->total_size - 1;
		swap_top(&st->data[top_idx], &st->data[top_idx - 1]);
	}
}
