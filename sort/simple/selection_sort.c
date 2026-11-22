/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 21:45:33 by balshoul          #+#    #+#             */
/*   Updated: 2026/11/22 15:24:24 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_on_top(t_data *data, int min_idx)
{
    int half;
	
    half = data->a.size / 2;
    if (min_idx <= half)
    	rotate_n(data, 'a', min_idx);
    else
    	reverse_rotate_n(data, 'a', data->a.size - min_idx);
}

void	selection_sort(t_data *data)
{
    int	min_idx;
    
    while (data->a.size > 3)
    {
        min_idx = find_min(&data->a);
        put_on_top(data, min_idx);
        push_b(data);
    }
    sort_three(data);
    while (data->b.size)
    	push_a(data);
}