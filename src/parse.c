/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:54:56 by teando            #+#    #+#             */
/*   Updated: 2024/12/07 21:34:51 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit((int)str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(t_stacks *st)
{
	for (int i = 0; i < st->a_size; i++)
	{
		for (int j = i + 1; j < st->a_size; j++)
		{
			if (st->data[i] == st->data[j])
				return (1);
		}
	}
	return (0);
}

int	parse_args(int ac, char **av, t_stacks *st)
{
	int i;
	long val;

	i = 1;
	while (i < ac)
	{
		if (!is_valid_number(av[i]))
			return (0);
		val = ft_atol(av[i]);
		if (val > INT_MAX || val < INT_MIN)
			return (0);
		st->data[i - 1] = (int)val;
		i++;
	}
	if (check_duplicates(st))
		return (0);
	return (1);
}