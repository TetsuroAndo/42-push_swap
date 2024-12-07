/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:57:13 by teando            #+#    #+#             */
/*   Updated: 2024/12/07 21:34:14 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int ac, char **av)
{
	t_stacks	st;

	if (ac < 2)
		return (0);
	st.total_size = ac - 1;
	st.a_size = ac - 1;
	st.b_size = 0;
	st.data = __builtin_alloca(sizeof(int) * st.total_size);
	if (!parse_args(ac, av, &st))
	{
		print_error();
		return (1);
	}
	if (is_sorted(&st))
		return (0);
	sort_stack(&st);
	return (0);
}