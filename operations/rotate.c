/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 12:40:35 by balshoul          #+#    #+#             */
/*   Updated: 2026/11/27 00:43:57 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_up(t_stack *stack)
{
    int new_tail;

    if (stack->size < 2)
    	return (1);
    new_tail = (get_tail(stack) + 1) % stack->cap;
    stack->buff[new_tail] = stack->buff[stack->head];
    stack->head = (stack->head + 1) % stack->cap;
    return (OK);
}

void	rotate_a(t_data *data)
{
    if (rotate_up(&data->a))
		return ;
	if (add_op(&data->lops, RA))
		data->malloc_err = 1;
}

void	rotate_b(t_data *data)
{
    if (rotate_up(&data->b))
		return ;
	if (add_op(&data->lops, RB))
		data->malloc_err = 1;
}

void	rotate_r(t_data *data)
{
    int	ra;
    int rb;

    ra = rotate_up(&data->a);
    rb = rotate_up(&data->b);
    if (ra != OK && rb != OK)
		return ;
	if (add_op(&data->lops, RR))
		data->malloc_err = 1;
}
