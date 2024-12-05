/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:35:07 by atomboy           #+#    #+#             */
/*   Updated: 2024/12/05 14:46:18 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	find_next_token(const char **s, char **start)
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

int	main(int argc, char **argv)
{
	const char	*s = argv[1];
	char		*start;
	char		*program_name;
	int			i;

	if (argc == 2)
	{
		program_name = argv[0];
		argc = ft_count_words(s, ' ') + 1;
		argv = __builtin_alloca((argc) * sizeof(char *));
		ft_memset(argv, 0, (argc) * sizeof(char *));
		argv[0] = program_name;
		i = 1;
		while (*s && i < argc)
		{
			if (!find_next_token(&s, &start))
				break ;
			argv[i] = __builtin_alloca(s - start + 1);
			ft_memcpy(argv[i], start, s - start);
			argv[i++][s - start] = '\0';
		}
		argv[i] = NULL;
	}
	return (push_swap(argc, argv));
}
