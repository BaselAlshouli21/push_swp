/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 12:55:17 by balshoul          #+#    #+#             */
/*   Updated: 2026/11/27 00:45:38 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_down(t_stack *stack)
{
	int	new_head;

	if (stack->size < 2)
		return (1);
	new_head = (stack->head - 1 + stack->cap) % stack->cap;
	stack->buff[new_head] = stack->buff[get_tail(stack)];
	stack->head = new_head;
	return (OK);
}

void	reverse_rotate_a(t_data *data)
{
    if (rotate_down(&data->a))
		return ;
	if (add_op(&data->lops, RRA))
		data->malloc_err = 1;
}

void	reverse_rotate_b(t_data *data)
{
    if (rotate_down(&data->b))
		return ;
	if (add_op(&data->lops, RRB))
		data->malloc_err = 1;
}

void	reverse_rotate_r(t_data *data)
{
    int	rra;
    int rrb;

    rra = rotate_down(&data->a);
    rrb = rotate_down(&data->b);
    if (rra != OK && rrb != OK)
		return ;
	if (add_op(&data->lops, RRR))
		data->malloc_err = 1;
}
