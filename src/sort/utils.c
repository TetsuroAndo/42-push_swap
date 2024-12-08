/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 05:46:18 by teando            #+#    #+#             */
/*   Updated: 2024/12/09 08:34:13 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*create_sorted_array(t_stacks *st)
{
	int	*sorted;

	sorted = malloc(sizeof(int) * st->a_size);
	if (!sorted)
		print_error(": malloc failed in create_sorted_array");
	ft_memcpy(sorted, st->data, sizeof(int) * st->a_size);
	bubble_sort(sorted, st->a_size);
	return (sorted);
}
