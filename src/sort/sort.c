/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:37:49 by teando            #+#    #+#             */
/*   Updated: 2024/12/07 21:41:24 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stacks *st)
{
	if (is_sorted(st))
		return ;
	quicksort_like(st, st->a_size);
}

// // B->Aへ戻す処理
// static void	move_all_b_to_a(t_stacks *st)
// {
// 	while (st->b_size > 0)
// 		pa(st, 1);
// }

void	quicksort_like(t_stacks *st, int size)
{
	int	pushed_small;
	int	pushed_large;
	int	rotated;

	// sizeは現在Aの上からsize要素を対象とする想定
	// 全てA側トップからsize要素がソート対象
	if (size <= 3)
	{
		small_sort_a(st, size);
		return ;
	}
	else if (size <= 5)
	{
		// 5個程度なら簡易な5ソート
		five_sort(st);
		return ;
	}
	int p1, p2;
	if (!get_pivots(st, size, &p1, &p2))
		return ; // エラー処理簡略
	// partition：p1, p2 を用いて3分割
	// アプローチ:
	// size回ループし、aのトップをチェック
	// if value < p1 => pb (小グループ)
	// if p1 <= value <= p2 => ra (中グループをaで前進)
	// if value > p2 => pbしてrb (大グループはbで回転して後方へ)
	pushed_small = 0;
	pushed_large = 0;
	rotated = 0;
	for (int i = 0; i < size; i++)
	{
		int val = st->data[0]; // Aトップ
		if (val < p1)
		{
			pb(st, 1);
			pushed_small++;
		}
		else if (val > p2)
		{
			pb(st, 1);
			rb(st, 1);
			pushed_large++;
		}
		else
		{
			ra(st, 1);
			rotated++;
		}
	}
	// 中間グループを元に戻す（rotated回 rra）
	for (int i = 0; i < rotated; i++)
		rra(st, 1);
	// 現在:
	// Aには中間グループのみ( p1 <= val <= p2 )
	// Bには小グループ(top付近)と大グループ(底付近)
	// Bの並び: [大グループ ... 小グループ]
	// 小グループ(少)は再帰的にソート
	// 大グループ(少)は再帰的にソート
	// 中グループは再帰的にソート
	// ソート順:
	// 1. 小グループ: Bにpushed_smallだけある (底の方)
	//    小グループは最も小さい値。これをAに戻す前にソートするが、小規模なら簡単に処理可能。
	//    Bにある小グループをAに戻すには、reverse rotateなどを駆使する必要あり
	// 大グループはB下方にいるので、一旦大グループを取り出すロジックが必要。
	// ここでは簡易的に、B全体をAへ戻してから、再分割する手順を示す。
	// 簡略化のため:
	// - 小グループと大グループをそれぞれ再度Aへ戻して、その都度quicksort_likeをかける戦略
	// 実際にはBで再帰すると操作数削減できるが、ここでは簡易化。
	// 戻す手順:
	// 現在Bには (大グループの要素数 = pushed_large) + (小グループの要素数 = pushed_small)
	// 大グループはBのトップからpushed_large要素 (rotateで正しい順番に戻すことも可能)
	// 小グループはその下にある。
	// 1. 大グループをBからAへ戻す
	for (int i = 0; i < pushed_large; i++)
	{
		// Bトップは大グループ
		pa(st, 1);
	}
	// 大グループをquicksort_like
	quicksort_like(st, pushed_large);
	// 次に小グループをBからAへ戻す
	for (int i = 0; i < pushed_small; i++)
	{
		// Bトップは小グループ
		pa(st, 1);
	}
	// 小グループはp1より小さいので既に小さい領域、これもsort
	quicksort_like(st, pushed_small);
	// 中グループ (A topから size - pushed_small - pushed_large)
	// 中グループはA上に残っているので再帰ソート
	quicksort_like(st, size - pushed_small - pushed_large);
}
