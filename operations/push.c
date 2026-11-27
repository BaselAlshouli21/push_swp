/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 23:24:20 by balshoul          #+#    #+#             */
/*   Updated: 2026/11/27 00:38:23 by basil42          ###   ########.fr       */
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
	if (add_op(&data->lops, PA))
		data->malloc_err = 1;
}


// take first element of a and push into b
void	push_b(t_data *data)
{
	if (push(&data->a, &data->b))
		return ;
	if (add_op(&data->lops, PB))
		data->malloc_err = 1;
}
