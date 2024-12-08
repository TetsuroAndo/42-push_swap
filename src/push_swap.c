/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:57:13 by teando            #+#    #+#             */
/*   Updated: 2024/12/08 15:59:32 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

int is_sorted(t_stacks *st)
{
	for (int i = 0; i < st->a_size - 1; i++)
		if (st->data[i] > st->data[i + 1])
			return (0);
	return (1);
}

int push_swap(int ac, char **av)
{
	t_stacks st;

	if (ac < 2)
		print_error("");
	st.total_size = ac - 1;
	st.a_size = ac - 1;
	st.b_size = 0;
	st.data = __builtin_alloca(sizeof(int) * st.total_size);
	if (!parse_args(ac, av, &st))
		print_error("");
	if (is_sorted(&st))
		return (0);
	sort_stack(&st);
	return (0);
}
