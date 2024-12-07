/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:55:05 by teando            #+#    #+#             */
/*   Updated: 2024/12/07 23:51:25 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** 与えられた操作(op)を実行し、必要に応じて表示
*/
void	execute_operation(t_stacks *st, t_operation op)
{
	static const char	*op_str[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
			"rr", "rra", "rrb", "rrr"};

	static void (*op_func[])(t_stacks *) = {swap_a, swap_b, NULL, push_a,
		push_b, rotate_a, rotate_b, NULL, rrotate_a, rrotate_b, NULL};
	if (op_func[op])
		op_func[op](st);
	if (op == OP_SS || op == OP_RR || op == OP_RRR)
	{
		op_func[op + 1](st);
	}
	ft_putendl_fd((char *)op_str[op], 1);
}
