/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:35:07 by atomboy           #+#    #+#             */
/*   Updated: 2024/12/08 15:59:00 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

static int find_next_token(const char **s, char **start)
{
	while (**s && **s == ' ')
		(*s)++;
	if (!**s)
		return (0);
	*start = (char *)*s;
	while (**s && **s != ' ')
		(*s)++;
	return (1);
}

int main(int ac, char **av)
{
	const char *s = av[1];
	char *start;
	int i;

	if (ac == 2)
	{
		ac = ft_count_words(s, ' ') + 1;
		av = __builtin_alloca(sizeof(char *) * ac);
		ft_bzero(av, (ac) * sizeof(char *));
		i = 1;
		while (*s && i < ac)
		{
			if (!find_next_token(&s, &start))
				break;
			av[i] = __builtin_alloca(s - start + 1);
			ft_memcpy(av[i], start, s - start);
			av[i++][s - start] = '\0';
		}
		av[i] = NULL;
	}
	return (push_swap(ac, av));
}
