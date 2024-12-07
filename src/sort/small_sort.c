/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:37:16 by teando            #+#    #+#             */
/*   Updated: 2024/12/07 21:37:28 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_three_sort(t_stacks *st)
{
	// Aに3要素: data[0], data[1], data[2]
	if (st->a_size < 2)
		return ;
	if (st->data[0] > st->data[1])
		sa(st, 1);
	if (st->a_size == 3 && st->data[1] > st->data[2])
	{
		rra(st, 1);
		if (st->data[0] > st->data[1])
			sa(st, 1);
	}
}

void	small_sort_a(t_stacks *st, int size)
{
	if (size <= 1)
		return ;
	if (size == 2 && st->data[0] > st->data[1])
		sa(st, 1);
	else if (size == 3)
		simple_three_sort(st);
}

void	five_sort(t_stacks *st)
{
	// 5要素を少ない操作でソート
	// 典型的には2要素をpbでbに移し、3要素をsort、bを戻すなど
	// ここでは詳細省略（実際の最適化は作り込みが必要）
	while (st->a_size > 3)
		pb(st, 1);
	simple_three_sort(st);
	while (st->b_size > 0)
	{
		pa(st, 1);
		if (st->data[0] > st->data[1])
			sa(st, 1);
	}
}
