/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 23:24:20 by balshoul          #+#    #+#             */
/*   Updated: 2026/11/17 13:41:31 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_stack *src, t_stack *dest)
{
    int new_head;

    if (src->size == 0)
    	return (1);
    new_head = (dest->head - 1 + dest->cap) % dest->cap;
    dest->head = new_head;
    dest->size++;
    dest->buff[new_head] = src->buff[src->head];
    src->head = (src->head + 1) % src->cap;
    src->size--;
    return (OK);
}


// take first element of b and push into a
void	push_a(t_data *data)
{
    if (push(&data->b, &data->a))
    	return ;
    data->ops.pa++;
    data->ops.total++;
    ft_printf("pa\n");
}


// take first element of a and push into b
void	push_b(t_data *data)
{
    if (push(&data->a, &data->b))
    	return ;
    data->ops.pb++;
    data->ops.total++;
    ft_printf("pb\n");
}
