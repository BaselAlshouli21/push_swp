/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 22:47:27 by balshoul          #+#    #+#             */
/*   Updated: 2026/11/16 23:23:02 by balshoul         ###   ########.fr       */
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
    data->ops.sa++;
    ft_printf("sa\n");
}

void	swap_b(t_data *data)
{
    if (swap_stack(&data->b))
    	return ;
    data->ops.sb++;
    ft_printf("sb\n");
}

void	swap_s(t_data *data)
{
    int	sa;
    int	sb;

    sa = swap_stack(&data->a);
    sb = swap_stack(&data->b);
    data->ops.ss += (sa == OK || sb == OK);
    if (sa == OK || sb == OK)
    	ft_printf("ss\n");
}