/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 05:46:18 by teando            #+#    #+#             */
/*   Updated: 2024/12/09 06:03:00 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_qsort(sorted, st->a_size, sizeof(int), compare);
	return (sorted);
}
