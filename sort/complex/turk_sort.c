/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <balshoul@student.42amman.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 19:52:33 by basil42           #+#    #+#             */
/*   Updated: 2026/11/24 20:48:07 by basil42          ###   ########.fr       */
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

static int	calculate_cost(t_data *data, int a_idx, int b_idx)
{
	int	a_half;
	int	b_half;
	int	a_cost;
	int	b_cost;

	a_half = data->a.size / 2;
	b_half = data->b.size / 2;
	a_cost = a_idx;
	b_cost = b_idx;
	if (b_idx <=  b_half && a_idx <= a_half)
		return (biggest(a_cost, b_cost));
	else if (b_idx > b_half && a_idx > a_half)
	{
		a_cost = data->a.size - a_idx;
		b_cost = data->b.size - b_half;
		return (biggest(a_cost, b_cost));
	}
	else
	{
		if (a_idx >= a_half)
			b_cost = data->a.size - a_idx;
		if (b_idx >= b_half)
			b_cost = data->b.size - b_idx;
	}
	return (a_cost + b_cost);
}

void turk_sort(t_data *data)
{
	for (int i = 0; i < data->a.size; i++)
	{
		int a_val = stack_at(&data->a, i);
		int target = find_target(&data->b, a_val);
		ft_printf("num: %d ", a_val);
		ft_printf("target: %d ", stack_at(&data->b, target));
		ft_printf("cost: %d\n", calculate_cost(data, i, target));
	}
}
