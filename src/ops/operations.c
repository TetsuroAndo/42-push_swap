/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:55:05 by teando            #+#    #+#             */
/*   Updated: 2024/12/08 20:12:24 by teando           ###   ########.fr       */
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

void	execute_operation(t_stacks *st, t_operation op)
{
	static const char	*op_str[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
			"rr", "rra", "rrb", "rrr"};

	static void (*op_func[])(t_stacks *) = {swap_a, swap_b, ss, push_btoa,
		push_atob, rotate_a, rotate_b, rr, rrotate_a, rrotate_b, rrr};
	op_func[op](st);
	ft_putendl_fd((char *)op_str[op], STDOUT_FILENO);
}
