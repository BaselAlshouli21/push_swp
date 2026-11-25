/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <balshoul@student.42amman.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 19:38:15 by basil42           #+#    #+#             */
/*   Updated: 2026/11/25 23:38:55 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_rotations get_rotation(int a, int b)
{
	if (a >= 0 && b >= 0)
		return (BOTH_R);
	if (a < 0 && b < 0)
		return (BOTH_RR);
	if (a >= 0 && b < 0)
		return (AR_BRR);
	return (ARR_BR);
}

static int	shared_cost(int a, int b)
{
	if ((a < 0 && b < 0) || (a >= 0 && b >= 0))
		return (biggest(absolute(a), absolute(b)));
	return (absolute(a) + absolute(b));
}

void	try_move(int a, int b, int *best, t_bmove *best_mv)
{
	int cost;

	cost = shared_cost(a, b);
	if (cost < *best)
	{
		best_mv->r = get_rotation(a, b);
		best_mv->a_move = absolute(a);
		best_mv->b_move = absolute(b);
		best_mv->cost = cost;
		*best = cost;
	}
}

t_bmove	calculate_cost(t_data *data, int a_idx, int b_idx)
{
	t_bmove	best_mv;
	int		best;
	int		ra;
	int		rb;

	best = INT_MAX;
	ra = (data->a.size - a_idx) % data->a.size;
	rb = (data->b.size - b_idx) % data->b.size;
	try_move(a_idx, b_idx, &best, &best_mv);
	try_move(-ra, -rb, &best, &best_mv);
	try_move(a_idx, -rb, &best, &best_mv);
	try_move(-ra, b_idx, &best, &best_mv);
	return (best_mv);
}

int	smallest_biggest(t_stack *a, int val, int *min_idx)
{
	int	best_match;
	int	target_idx;
	int	i;

	best_match = -1;
	target_idx = -1;
	*min_idx = 0;
	i = 0;
	while (i < a->size)
	{
		if ((stack_at(a, i) > val) &&
			(target_idx == -1 || stack_at(a, i) < best_match))
		{
			best_match = stack_at(a, i);
			target_idx = i;
		}
		if (stack_at(a, i) < stack_at(a, *min_idx))
			*min_idx = i;
		i++;
	}
	if (target_idx == -1)
		return (*min_idx);
	return (target_idx);
}
