/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 22:09:58 by basil42           #+#    #+#             */
/*   Updated: 2026/11/14 20:19:57 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_arr(t_stack *stack, char name)
{
	int	i;
	int	tail_idx;
	
	tail_idx = (stack->head + stack->size - 1) % stack->cap;
	ft_printf("stack [%c] \n", name);
	ft_printf("head_idx=%d, tail_idx=%d, size=%d, cap=%d):\n[ ",
		stack->head, tail_idx, stack->size, stack->cap);
	i = 0;
	while (stack->cap > i)
	{
		ft_printf("%d ", stack->buff[i]);
		i++;
	}
	ft_printf("]\n");
}

void	print_stacks(t_data *data)
{
	ft_printf("\n");
	print_arr(&data->a, 'a');
	ft_printf("\n");
	print_arr(&data->b, 'b');
	ft_printf("\n");
}

void	print_stats(t_data *data, int mode)
{
	if (mode == 1)
		print_stacks(data);
	if (data->bench_mode == 1)
		ft_printf("bench mode: [TRUE]\n");
	else
		ft_printf("bench mode: [FALSE]\n");
	switch(data->algo)
	{
		case ALGO_SIMPLE:
			ft_printf("algo      : [SIMPLE]\n");
			break;
		case ALGO_INTERMEDIATE:
			ft_printf("algo      : [MEDIUM]\n");
			break;
		case ALGO_COMPLEX:
			ft_printf("algo      : [COMPLEX]\n");
			break;
		default:
			ft_printf("algo      : [ADAPTIVE]\n");
			break;
	}
}