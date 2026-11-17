/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 12:55:17 by balshoul          #+#    #+#             */
/*   Updated: 2026/11/17 13:41:59 by balshoul         ###   ########.fr       */
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
    data->ops.rra++;
    data->ops.total++;
    ft_printf("rra\n");
}

void	reverse_rotate_b(t_data *data)
{
    if (rotate_down(&data->b))
        return ;
    data->ops.rrb++;
    data->ops.total++;
    ft_printf("rrb\n");
}

void	reverse_rotate_r(t_data *data)
{
    int	rra;
    int rrb;

    rra = rotate_down(&data->a);
    rrb = rotate_down(&data->b);
    if (rra == OK || rrb == OK)
    {
        data->ops.rrr++;
        data->ops.total++;
        ft_printf("rrr\n");
    }
}