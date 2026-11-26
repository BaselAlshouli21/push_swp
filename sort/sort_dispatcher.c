/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dispatcher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:32:18 by balshoul          #+#    #+#             */
/*   Updated: 2026/11/26 22:03:52 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_adaptive(t_data *data)
{
	data->adaptive = 1;
	if (data->disorder < 0.2)
	{
		selection_sort(data);
		data->algo = ALGO_SIMPLE;
		data->complexity = SIMPLE;
	}
	else if (0.2 <= data->disorder && data->disorder < 0.5)
	{
		chunk_sort(data);
		data->algo = ALGO_INTERMEDIATE;
		data->complexity = MEDIUM;
	}
	else
	{
		turk_sort(data);
		data->algo = ALGO_COMPLEX;
		data->complexity = COMPLEX;
	}
}

int	sort_dispatcher(t_data *data)
{
	data->disorder = compute_disorder(data->a.buff, data->a.size);
    if (data->disorder == 0.0)
    	return (ERR_SORTED_STACK);
    if (data->algo == ALGO_SIMPLE)
    	selection_sort(data);
    else if (data->algo == ALGO_INTERMEDIATE)
    	chunk_sort(data);
    else if (data->algo == ALGO_COMPLEX)
    	turk_sort(data);
    else if (data->algo == ALGO_ADAPTIVE)
    	sort_adaptive(data);
    return (OK);
}
