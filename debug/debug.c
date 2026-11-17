/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 22:09:58 by basil42           #+#    #+#             */
/*   Updated: 2026/11/17 13:53:14 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack, char name)
{
	int	i;
	int	tail;

	tail = get_tail(stack);
	ft_printf("stack [%c] (head=%d, tail=%d, size=%d/%d)\n  logical: [ ",
		name, stack->head, tail, stack->size, stack->cap);
	i = 0;
	while (i < stack->size)
		ft_printf("%d ", stack_at(stack, i++));
	ft_printf("]\n  raw_buf: [ ");
	i = 0;
	while (i < stack->cap)
	{
		if (i == stack->head && stack->size > 0)
			ft_printf("H:");
		if (i == tail)
			ft_printf("T:");
		ft_printf("%d ", stack->buff[i++]);
	}
	ft_printf("]\n");
}

void	print_stacks(t_data *data)
{
	ft_printf("\n");
	print_stack(&data->a, 'a');
	ft_printf("\n");
	print_stack(&data->b, 'b');
	ft_printf("\n");
}

void	print_stats(t_data *data, int mode)
{
	if (mode == 1)
		print_stacks(data);
	print_disorder(data);
	if (data->bench_mode == 1)
		ft_printf("bench mode : [TRUE]\n");
	else
		ft_printf("bench mode : [FALSE]\n");
	switch(data->algo)
	{
		case ALGO_SIMPLE:
			ft_printf("algo       : [SIMPLE]\n");
			break;
		case ALGO_INTERMEDIATE:
			ft_printf("algo       : [MEDIUM]\n");
			break;
		case ALGO_COMPLEX:
			ft_printf("algo       : [COMPLEX]\n");
			break;
		default:
			ft_printf("algo       : [ADAPTIVE]\n");
			break;
	}
}