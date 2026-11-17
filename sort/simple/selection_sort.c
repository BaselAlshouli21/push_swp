/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 21:45:33 by balshoul          #+#    #+#             */
/*   Updated: 2026/11/17 16:44:38 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_n(t_data *data, int n)
{
    while (n--)
    	rotate_a(data);
}
static void	reverse_rotate_n(t_data *data, int n)
{
    while (n--)
    	reverse_rotate_a(data);
}

static void	put_on_top(t_data *data, int min_idx)
{
    int half;
	
    half = data->a.size / 2;
    if (min_idx <= half)
    	rotate_n(data, min_idx);
    else
    	reverse_rotate_n(data, data->a.size - min_idx);
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