/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:30:18 by teando            #+#    #+#             */
/*   Updated: 2024/12/07 21:39:13 by teando           ###   ########.fr       */
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
	int *data;      // 両スタック(a,b)共通の配列
	int a_size;     // スタックaに積まれている要素数
	int b_size;     // スタックbに積まれている要素数
	int total_size; // 確保した配列の合計サイズ
}		t_stacks;

// main
int		push_swap(int ac, char **av);

// parse
int		parse_args(int ac, char **av, t_stacks *st);
int		check_duplicates(t_stacks *st);

// error
int		is_valid_number(const char *str);
int		print_error(void);

// command
void	sa(t_stacks *st, int print);
void	sb(t_stacks *st, int print);
void	ss(t_stacks *st, int print);
void	pa(t_stacks *st, int print);
void	pb(t_stacks *st, int print);
void	ra(t_stacks *st, int print);
void	rb(t_stacks *st, int print);
void	rr(t_stacks *st, int print);
void	rra(t_stacks *st, int print);
void	rrb(t_stacks *st, int print);
void	rrr(t_stacks *st, int print);

// sort
void	sort_stack(t_stacks *st);
void	quicksort_like(t_stacks *st, int size);

// small_sort
void	small_sort_a(t_stacks *st, int size);
void	simple_three_sort(t_stacks *st);
void	five_sort(t_stacks *st);

// median
int		get_pivots(t_stacks *st, int size, int *p1, int *p2);

// utils
int		is_sorted(t_stacks *st);

#endif