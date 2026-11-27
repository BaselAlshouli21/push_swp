/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 22:47:27 by balshoul          #+#    #+#             */
/*   Updated: 2026/11/27 00:41:48 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_stack(t_stack *stack)
{
    int	second_idx;
    int	temp;
    
    if (stack->size < 2)
    	return (1);
    second_idx = (stack->head + 1) % stack->cap;
    temp = stack->buff[stack->head];
    stack->buff[stack->head] = stack->buff[second_idx];
    stack->buff[second_idx] = temp;
	return (OK);
}

void	swap_a(t_data *data)
{
    if (swap_stack(&data->a))
    	return ;
    if (add_op(&data->lops, SA))
		data->malloc_err = 1;
}

void	swap_b(t_data *data)
{
	if (swap_stack(&data->b))
		return ;
	if (add_op(&data->lops, SB))
		data->malloc_err = 1;
}

void	swap_s(t_data *data)
{
    int	sa;
    int	sb;

    sa = swap_stack(&data->a);
    sb = swap_stack(&data->b);
    if (sa != OK && sb != OK)
		return ;
	if (add_op(&data->lops, SS))
		data->malloc_err = 1;
}
