/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:37:49 by teando            #+#    #+#             */
/*   Updated: 2024/12/09 08:53:57 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_count(int size)
{
	if (size <= 100)
		return (4);
	else if (size <= 500)
		return (8);
	else
		return (size / 60);
}

static void	push_chunk_to_b(t_stacks *st, int *sorted, int start_idx,
		int end_idx)
{
	int	min_val;
	int	max_val;
	int	needed;
	int	pushed;

	min_val = sorted[start_idx];
	max_val = sorted[end_idx];
	needed = (end_idx - start_idx + 1);
	pushed = 0;
	while (pushed < needed)
	{
		if (st->data[0] >= min_val && st->data[0] <= max_val)
		{
			execute_operation(st, OP_PB);
			pushed++;
		}
		else
			execute_operation(st, OP_RA);
	}
}

static void	push_back_to_a(t_stacks *st)
{
	int	index;
	int	max_idx;
	int	j;

	while (st->b_size > 0)
	{
		max_idx = 0;
		j = 0;
		while (++j < st->b_size)
		{
			index = st->total_size - 1;
			if (st->data[index - j] > st->data[index - max_idx])
				max_idx = j;
		}
		if (max_idx <= st->b_size / 2)
			while (max_idx-- > 0)
				execute_operation(st, OP_RB);
		else
			while (max_idx++ < st->b_size)
				execute_operation(st, OP_RRB);
		execute_operation(st, OP_PA);
	}
}

static void	turk_sort(t_stacks *st)
{
	int		i;
	t_chunk	ch;

	ch.original_a_size = st->a_size;
	ch.sorted = create_sorted_array(st);
	ch.chunk_count = get_chunk_count(ch.original_a_size);
	ch.chunk_size = ch.original_a_size / ch.chunk_count;
	i = 0;
	while (i < ch.chunk_count)
	{
		ch.start_idx = i * ch.chunk_size;
		ch.end_idx = ch.start_idx + ch.chunk_size - 1;
		if (i == ch.chunk_count - 1)
			ch.end_idx = ch.original_a_size - 1;
		push_chunk_to_b(st, ch.sorted, ch.start_idx, ch.end_idx);
		i++;
	}
	push_back_to_a(st);
	free(ch.sorted);
}

void	sort_stack(t_stacks *st)
{
	if (is_sorted(st))
		return ;
	if (st->a_size <= 3)
		three_sort(st);
	else if (st->a_size <= 5)
		five_sort(st);
	else
		turk_sort(st);
}
