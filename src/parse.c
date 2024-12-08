/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:54:56 by teando            #+#    #+#             */
/*   Updated: 2024/12/08 21:41:43 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
		if (!ft_isdigit((int)str[i++]))
			return (0);
	return (1);
}

static int	check_duplicates(t_stacks *st)
{
	int	i;
	int	j;

	i = -1;
	while (++i < st->a_size - 1)
	{
		j = i;
		while (++j < st->a_size)
			if (st->data[i] == st->data[j])
				return (1);
	}
	return (0);
}

int	parse_args(int ac, char **av, t_stacks *st)
{
	long	val;
	int		i;

	i = 0;
	while (++i < ac)
	{
		if (!is_valid_number(av[i]))
			return (0);
		val = ft_strtol(av[i], NULL, 10);
		if (val > INT_MAX || val < INT_MIN)
			return (0);
		st->data[i - 1] = (int)val;
	}
	if (check_duplicates(st))
		return (0);
	return (1);
}
