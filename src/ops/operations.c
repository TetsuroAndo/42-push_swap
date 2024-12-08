/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:55:05 by teando            #+#    #+#             */
/*   Updated: 2024/12/09 08:53:34 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_operation(t_operation op)
{
	const char	*op_str[] = {"sa", "sb", "pa", "pb", "ra", "rb", "rra", "rrb"};

	ft_putendl_fd((char *)op_str[op], STDOUT_FILENO);
}

void	execute_operation(t_stacks *st, t_operation op)
{
	if (op < 0 || op > 10)
		return ;
	if (op == OP_SA)
		swap_a(st);
	else if (op == OP_SB)
		swap_b(st);
	else if (op == OP_PA)
		push_btoa(st);
	else if (op == OP_PB)
		push_atob(st);
	else if (op == OP_RA)
		rotate_a(st);
	else if (op == OP_RB)
		rotate_b(st);
	else if (op == OP_RRA)
		rrotate_a(st);
	else if (op == OP_RRB)
		rrotate_b(st);
	print_operation(op);
}
