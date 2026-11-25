/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <balshoul@student.42amman.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 19:52:33 by basil42           #+#    #+#             */
/*   Updated: 2026/11/25 23:51:25 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_target(t_stack *b, int val)
{
	int	best_match;
	int	target_idx;
	int	max_idx;
	int	i;

	best_match = -1;
	target_idx = -1;
	max_idx = 0;
	i = 0;
	while (i < b->size)
	{
		if ((stack_at(b, i) < val) &&
			(target_idx == -1 || stack_at(b, i) > best_match))
		{
			best_match = stack_at(b, i);
			target_idx = i;
		}
		if (stack_at(b, i) > stack_at(b, max_idx))
			max_idx = i;
		i++;
	}
	if (target_idx == -1)
		return (max_idx);
	return (target_idx);
}

static void find_cheapest(t_data *data, t_bmove *best_mv)
{
	t_bmove	min_move;
	int		a_idx;
	int		b_idx;
	
	a_idx = 0;
	min_move.cost = INT_MAX;
	while (a_idx < data->a.size)
	{
		b_idx = find_target(&data->b, stack_at(&data->a, a_idx));
		*best_mv = calculate_cost(data, a_idx, b_idx);
		if (best_mv->cost < min_move.cost)
			min_move = *best_mv;
		a_idx++;
	}
	*best_mv = min_move;
}



static void	put_on_top(t_data *data, t_bmove *best_mv)
{
	t_rotations r;
	int			cost;

	r = best_mv->r;
	cost = best_mv->cost;
	if (r == BOTH_R)
		rotate_r_n(data, cost);
	else if (r == BOTH_RR)
		reverse_rotate_r_n(data, cost);
	else if (r == AR_BRR)
	{
		rotate_n(data, 'a', best_mv->a_move);
		reverse_rotate_n(data, 'b', best_mv->b_move);
	}
	else if (r == ARR_BR)
	{
		rotate_n(data, 'b', best_mv->b_move);
		reverse_rotate_n(data, 'a', best_mv->a_move);
	}
}

static void	move_to_a(t_data *data, int *min_idx)
{
	int	cheapest;
	int	val;

	while (data->b.size > 0)
	{
		val = stack_at(&data->b, 0);
		cheapest = smallest_biggest(&data->a, val, min_idx);
		if (cheapest <= data->a.size / 2)
			rotate_n(data, 'a', cheapest);
		else
			reverse_rotate_n(data, 'a', data->a.size - cheapest);
		if (data->b.size == 1)
			*min_idx = (*min_idx - cheapest + data->a.size) % data->a.size;
		push_a(data);
	}
}

void turk_sort(t_data *data)
{
	t_bmove best_mv;
	int		min_idx;

	push_b(data);
	push_b(data);
	min_idx = 0;
	while (data->a.size > 3)
	{
		find_cheapest(data, &best_mv);
		put_on_top(data, &best_mv);
		push_b(data);
	}
	sort_three(data);
	move_to_a(data, &min_idx);
	if (stack_at(&data->a, min_idx + 1) > stack_at(&data->a, 0))
		min_idx = 0;
	else
		min_idx++;
	if (min_idx <= data->a.size / 2)
		rotate_n(data, 'a', min_idx);
	else
		reverse_rotate_n(data, 'a', data->a.size - min_idx);
}
