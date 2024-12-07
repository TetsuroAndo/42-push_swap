/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:35:22 by teando            #+#    #+#             */
/*   Updated: 2024/12/08 00:15:32 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int	get_pivots(t_stacks *st, int size, int *p1, int *p2)
{
	int	*copy;

	copy = __builtin_alloca(sizeof(int) * size);
	if (!copy)
		return (0);
	for (int i = 0; i < size; i++)
		copy[i] = st->data[i];
	sort_array(copy, size);
	*p1 = copy[size / 3];
	*p2 = copy[(size * 2) / 3];
	return (1);
}
