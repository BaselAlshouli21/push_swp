/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 19:48:23 by balshoul          #+#    #+#             */
/*   Updated: 2026/11/22 19:02:01 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	normalize_ranks(t_data *data)
{
    int	count;
    int	a_idx;
    int	i;
    
    a_idx = 0;
    while (a_idx < data->a.size)
    {
        count = 0;
        i = 0;
        while (i < data->a.size)
        {
            if (stack_at(&data->a, i) < stack_at(&data->a, a_idx))
            	count++;
            i++;
        }
        data->b.buff[a_idx++] = count;
    }
    i = 0;
    while (i < data->a.size)
    {
        data->a.buff[(data->a.head + i) % data->a.cap] = data->b.buff[i];
        i++;
    }
    ft_bzero(data->b.buff, sizeof(int) * data->b.cap);
}

static int	get_chunk_size(t_stack *s)
{
    int	sqrt;

    if (s->cap <= 1)
    	return (1);
    if (s->cap == 100)
    	return (20);
    else if (s->cap == 500)
    	return (30);
    sqrt = 1;
    while ((sqrt * sqrt) < s->cap)
        sqrt++;
    return ((s->cap / sqrt) * 1.5);
}

static void	move_to_b(t_data *data, int chunk_size)
{
    int	pushed;

    pushed = 0;
    while (data->a.size > 0)
    {
        if (stack_at(&data->a, 0) <= pushed)
        {
            push_b(data);
            rotate_b(data);
            pushed++;
        }
        else if (pushed < stack_at(&data->a, 0) && stack_at(&data->a, 0) <=	 pushed + chunk_size)
        {
        	push_b(data);
            pushed++;
        }
        else
        	rotate_a(data);
    }
}

static void move_to_a(t_data *data)
{
    int	half;
    int max_idx;
    while (data->b.size > 0)
    {
        half = data->b.size / 2;
        max_idx = search_stack(&data->b, data->b.size - 1);
        if (max_idx >= half)
        	reverse_rotate_n(data, 'b', data->b.size - max_idx);
        else
        	rotate_n(data, 'b', max_idx);
        push_a(data);
    }
}

void	chunk_sort(t_data *data)
{
    int	chunk_size;
    
    chunk_size = get_chunk_size(&data->a);
    normalize_ranks(data);
    move_to_b(data, chunk_size);
    move_to_a(data);
}