/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:55:05 by teando            #+#    #+#             */
/*   Updated: 2024/12/07 20:56:08 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// スタックaはdata[0]〜data[a_size-1]
// スタックbはdata[total_size-1], data[total_size-2], ... と後ろから積む
// よってbのtopはdata[total_size - 1]で、b_sizeが増えるたびに前に広がる。

static void	swap_top(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

// sa: aの先頭2要素をスワップ
void	sa(t_stacks *st, int print)
{
	if (st->a_size > 1)
		swap_top(&st->data[0], &st->data[1]);
	if (print)
		ft_putendl_fd("sa", 1);
}

// sb: bの先頭2要素をスワップ
void	sb(t_stacks *st, int print)
{
	int	top_idx;

	if (st->b_size > 1)
	{
		top_idx = st->total_size - 1;
		swap_top(&st->data[top_idx], &st->data[top_idx - 1]);
	}
	if (print)
		ft_putendl_fd("sb", 1);
}

// ss: saとsb同時実行
void	ss(t_stacks *st, int print)
{
	sa(st, 0);
	sb(st, 0);
	if (print)
		ft_putendl_fd("ss", 1);
}

// pa: bのtopをaへ移動
void	pa(t_stacks *st, int print)
{
	int	b_top;

	if (st->b_size < 1)
		return ;
	b_top = st->total_size - 1;
	// aを一つ後ろにシフト
	for (int i = st->a_size; i > 0; i--)
		st->data[i] = st->data[i - 1];
	// b_top要素をa[0]へ移動
	st->data[0] = st->data[b_top];
	// bを一つ縮める
	st->b_size--;
	// bトップ要素を無効化する必要はないが、わかりやすいように0代入
	st->data[b_top] = 0;
	st->a_size++;
	if (print)
		ft_putendl_fd("pa", 1);
}

// pb: aのtopをbへ移動
void	pb(t_stacks *st, int print)
{
	int	b_top;

	if (st->a_size < 1)
		return ;
	b_top = st->total_size - 1 - (st->b_size);
	// b_top+1が新トップ、そこへa[0]を移す
	st->data[b_top] = st->data[0];
	// aを1つ前へシフト
	for (int i = 0; i < st->a_size - 1; i++)
		st->data[i] = st->data[i + 1];
	st->a_size--;
	st->b_size++;
	// aの末尾をクリア(任意)
	st->data[st->a_size] = 0;
	if (print)
		ft_putendl_fd("pb", 1);
}

// ra: aを1回回転
void	ra(t_stacks *st, int print)
{
	int	tmp;

	if (st->a_size > 1)
	{
		tmp = st->data[0];
		for (int i = 0; i < st->a_size - 1; i++)
			st->data[i] = st->data[i + 1];
		st->data[st->a_size - 1] = tmp;
	}
	if (print)
		ft_putendl_fd("ra", 1);
}

// rb: bを1回回転
void	rb(t_stacks *st, int print)
{
	int	top_idx;
	int	tmp;

	if (st->b_size > 1)
	{
		top_idx = st->total_size - 1;
		tmp = st->data[top_idx];
		for (int i = 0; i < st->b_size - 1; i++)
			st->data[top_idx - i] = st->data[top_idx - i - 1];
		st->data[top_idx - (st->b_size - 1)] = tmp;
	}
	if (print)
		ft_putendl_fd("rb", 1);
}

// rr: raとrb同時実行
void	rr(t_stacks *st, int print)
{
	ra(st, 0);
	rb(st, 0);
	if (print)
		ft_putendl_fd("rr", 1);
}

// rra: aを逆回転
void	rra(t_stacks *st, int print)
{
	int	tmp;

	if (st->a_size > 1)
	{
		tmp = st->data[st->a_size - 1];
		for (int i = st->a_size - 1; i > 0; i--)
			st->data[i] = st->data[i - 1];
		st->data[0] = tmp;
	}
	if (print)
		ft_putendl_fd("rra", 1);
}

// rrb: bを逆回転
void	rrb(t_stacks *st, int print)
{
	int	top_idx;
	int	bottom_idx;
	int	tmp;

	if (st->b_size > 1)
	{
		top_idx = st->total_size - 1;
		bottom_idx = top_idx - (st->b_size - 1);
		tmp = st->data[bottom_idx];
		for (int i = bottom_idx; i < top_idx; i++)
			st->data[i] = st->data[i + 1];
		st->data[top_idx] = tmp;
	}
	if (print)
		ft_putendl_fd("rrb", 1);
}

// rrr: rraとrrb同時実行
void	rrr(t_stacks *st, int print)
{
	rra(st, 0);
	rrb(st, 0);
	if (print)
		ft_putendl_fd("rrr", 1);
}
