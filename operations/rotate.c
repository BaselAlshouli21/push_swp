/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 12:40:35 by balshoul          #+#    #+#             */
/*   Updated: 2026/11/17 13:02:04 by balshoul         ###   ########.fr       */
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
    data->ops.ra++;
    ft_printf("ra\n");
}

void	rotate_b(t_data *data)
{
    if (rotate_up(&data->b))
        return ;
    data->ops.rb++;
    ft_printf("rb\n");
}

void	rotate_r(t_data *data)
{
    int	ra;
    int rb;

    ra = rotate_up(&data->a);
    rb = rotate_up(&data->b);
    if (ra == OK || rb == OK)
    {
        data->ops.rr++;
        ft_printf("rr\n");
    }
}
