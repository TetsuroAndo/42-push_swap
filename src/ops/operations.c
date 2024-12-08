/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:55:05 by teando            #+#    #+#             */
/*   Updated: 2024/12/09 03:32:23 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ss(t_stacks *st)
{
	swap_a(st);
	swap_b(st);
}

static void	rr(t_stacks *st)
{
	rotate_a(st);
	rotate_b(st);
}

static void	rrr(t_stacks *st)
{
	rrotate_a(st);
	rrotate_b(st);
}

static int	check_duplicates(t_stacks *st)
{
	for (int i = 0; i < st->a_size - 1; i++)
	{
		for (int j = i + 1; j < st->a_size; j++)
		{
			if (st->data[i] == st->data[j])
				return (1); // 重複あり
		}
	}
	for (int i = st->total_size - st->b_size; i < st->total_size - 1; i++)
	{
		for (int j = i + 1; j < st->total_size; j++)
		{
			if (st->data[i] == st->data[j])
				return (1); // 重複あり
		}
	}
	return (0); // 重複なし
}

void	print_stacks(t_stacks *st)
{
	ft_printf("A stack (%d): ", st->a_size);
	for (int i = 0; i < st->a_size; i++)
		ft_printf("%d ", st->data[i]);
	ft_printf("\n");
	ft_printf("B stack (%d): ", st->b_size);
	for (int i = st->total_size - 1; i > st->total_size - st->b_size - 1; i--)
		ft_printf("%d ", st->data[i]);
	ft_printf("\n");
}

int			g_operation_count = 0; // デバッグ

void	execute_operation(t_stacks *st, t_operation op)
{
	static const char	*op_str[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
			"rr", "rra", "rrb", "rrr"};

	static void (*op_func[])(t_stacks *) = {swap_a, swap_b, ss, push_btoa,
		push_atob, rotate_a, rotate_b, rr, rrotate_a, rrotate_b, rrr};
	// 操作前の重複チェック
	if (check_duplicates(st))
	{
		ft_printf("Error: Duplicates found before %s operation\n", op_str[op]);
		exit(1);
	}
	// ft_printf("Command try: %d\n", g_operation_count + 1);
	// //デバッグ: 操作前の配列の状態を表示
	// ft_printf("Before %s:\n", op_str[op]);
	// print_stacks(st);
	/*
		*/
	op_func[op](st);
	ft_putendl_fd((char *)op_str[op], STDOUT_FILENO);
	g_operation_count++;
	/*
		*/
	// //デバッグ: 操作後の配列の状態を表示
	// ft_printf("After %s:\n", op_str[op]);
	// print_stacks(st);
	// ft_printf("\n");
}
