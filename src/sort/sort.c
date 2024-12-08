/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:37:49 by teando            #+#    #+#             */
/*   Updated: 2024/12/09 01:11:24 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * ターク法(Chunkベース)実装方針:
 * 1. 全要素をコピーしてソート済み配列を用意する
 * 2. 要素数に応じてチャンク数を決定(例: ~100要素で5~7チャンク、500要素で11など)
 * 3. チャンク境界に従い、AからBへ適切な要素を移動
 *    - チャンク内の要素はBへ移す
 *    - 小さい要素はB下部へ回すなどして整理可能（本例では単純にpushのみを行い、位置調整は省略）
 * 4. 全チャンク移動後、Bにある全要素を最大値から順にAへ戻して完成
 */

/* 配列をバブルソートする補助関数 */
static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

/* ソート済み配列を取得する関数 */
static int	*get_sorted_array(t_stacks *st)
{
	int	*copy;
	int	i;

	copy = __builtin_alloca(sizeof(int) * st->a_size);
	if (!copy)
		print_error(": Allocation failed");
	i = -1;
	while (i++ < st->a_size)
		copy[i] = st->data[i];
	sort_array(copy, st->a_size);
	return (copy);
}

/*
 * 指定された範囲の値(チャンク)をAからBへ移動する
 * chunk_min <= value <= chunk_maxの値を全てBへプッシュ
 */
static void	push_chunk_to_b(t_stacks *st, int chunk_min, int chunk_max)
{
	int	i;
	int	size;

	size = st->a_size + st->b_size;
	i = 0;
	while (i < size && st->a_size > 0)
	{
		if (st->data[0] >= chunk_min && st->data[0] <= chunk_max)
		{
			execute_operation(st, OP_PB);
		}
		else
		{
			execute_operation(st, OP_RA);
		}
		i++;
	}
}

/*
 * Bスタックには降順に近い形で要素が積まれていることを期待し、
 * 最大値をトップに持ってきてAへ戻す処理を繰り返す。
 */
static int	get_max_index_in_b(t_stacks *st)
{
	int	max_val;
	int	max_idx;
	int	i;
	int	b_start;

	b_start = st->total_size - st->b_size;
	max_val = st->data[b_start];
	max_idx = b_start;
	i = b_start;
	while (i < st->total_size)
	{
		if (st->data[i] > max_val)
		{
			max_val = st->data[i];
			max_idx = i;
		}
		i++;
	}
	return (max_idx);
}

/*
 * トップへ持ってくるのに上下どちら回転が有利か比較して回転。
 * 簡略化のため一方向で回転を実行(改善可)。
 */
static void	rotate_b_to_max(t_stacks *st, int max_idx)
{
	if ((max_idx - (st->total_size - st->b_size)) < (st->b_size / 2))
	{
		while (st->total_size - 1 != max_idx)
		{
			execute_operation(st, OP_RB);
			max_idx++;
		}
	}
	else
	{
		while (st->total_size - 1 != max_idx)
		{
			execute_operation(st, OP_RRB);
			max_idx--;
		}
	}
}

/*
 * 全チャンクをBへ移した後、BからAへ最大値から順に戻す
 */
static void	push_all_back_to_a(t_stacks *st)
{
	int	max_idx;

	while (st->b_size > 0)
	{
		max_idx = get_max_index_in_b(st);
		rotate_b_to_max(st, max_idx);
		execute_operation(st, OP_PA);
	}
}

/*
 * 大きさに応じてチャンク数を決める(簡易的な決定方法)
 */
static int	get_chunk_count(int size)
{
	if (size <= 100)
		return (5);
	else if (size <= 500)
		return (11);
	else
		return (size / 45); /* 適当な値。実装者が微調整可能 */
}

/*
 * メインのターク法
 * 1. ソート済み配列取得
 * 2. チャンク数計算・チャンク境界で分割
 * 3. 各チャンクをAからBへ
 * 4. 全てBへ移動後、BからAへ戻す
 */
static void	turk_method(t_stacks *st)
{
	int	*sorted;
	int	chunks;
	int	chunk_size;
	int	i;
	int	start;
	int	end;

	sorted = get_sorted_array(st);
	chunks = get_chunk_count(st->a_size);
	chunk_size = st->a_size / chunks;
	i = 0;
	while (i < chunks - 1)
	{
		start = i * chunk_size;
		end = (i + 1) * chunk_size - 1;
		push_chunk_to_b(st, sorted[start], sorted[end]);
		i++;
	}
	/* 最終チャンク(端数対応) */
	push_chunk_to_b(st, sorted[i * chunk_size], sorted[st->a_size - 1]);
	push_all_back_to_a(st);
}

void	sort_stack(t_stacks *st)
{
	const int	size = st->a_size;

	if (size <= 3)
		small_sort_a(st, size);
	else if (size <= 5)
		five_sort(st);
	else
		turk_method(st);
}
