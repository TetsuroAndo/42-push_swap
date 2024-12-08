/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:30:18 by teando            #+#    #+#             */
/*   Updated: 2024/12/09 01:40:55 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stacks
{
	int	*data;
	int	a_size;
	int	b_size;
	int	total_size;
}		t_stacks;

typedef enum e_operation
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
}		t_operation;

/* main */
int		push_swap(int ac, char **av);

/* parse */
int		parse_args(int ac, char **av, t_stacks *st);

/* error */
int		print_error(const char *str);

/* sort */
void	sort_stack(t_stacks *st);
void	three_sort(t_stacks *st);
void	five_sort(t_stacks *st);

/* utils */
int		is_sorted(t_stacks *st);

/* operation */
void	execute_operation(t_stacks *st, t_operation op);

/* ops */
void	swap_a(t_stacks *st);
void	swap_b(t_stacks *st);
void	rotate_a(t_stacks *st);
void	rotate_b(t_stacks *st);
void	rrotate_a(t_stacks *st);
void	rrotate_b(t_stacks *st);
void	push_btoa(t_stacks *st);
void	push_atob(t_stacks *st);

#endif