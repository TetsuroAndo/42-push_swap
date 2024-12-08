/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 05:46:18 by teando            #+#    #+#             */
/*   Updated: 2024/12/09 08:04:21 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_swap(void *a, void *b, size_t size)
{
	char	temp[size];

	ft_memcpy(temp, a, size);
	ft_memcpy(a, b, size);
	ft_memcpy(b, temp, size);
}

static void	bubble_sort(void *array, size_t len, size_t size,
		int (*compare)(const void *, const void *))
{
	size_t	i;
	size_t	j;
	char	*base;
	int		swapped;

	base = (char *)array;
	i = 0;
	while (i < len - 1)
	{
		swapped = 0;
		j = 0;
		while (j < len - i - 1)
		{
			if (compare(base + j * size, base + (j + 1) * size) > 0)
			{
				bubble_swap(base + j * size, base + (j + 1) * size, size);
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			break ;
		i++;
	}
}

/**
 * @brief スタックAのデータをもとにソート済み配列を作成
 */
static int	compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int	*create_sorted_array(t_stacks *st)
{
	int	*sorted;

	sorted = malloc(sizeof(int) * st->a_size);
	if (!sorted)
		print_error(": malloc failed in create_sorted_array");
	ft_memcpy(sorted, st->data, sizeof(int) * st->a_size);
	bubble_sort(sorted, st->a_size, sizeof(int), compare);
	return (sorted);
}
