/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 22:09:58 by basil42           #+#    #+#             */
/*   Updated: 2026/11/14 12:47:52 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	for (int i = 0; i < stack->size; i++)
		ft_printf("[%d]: [%d]\n", i, stack->buff[i]);
	ft_printf("head idx: %d\n", stack->head);
	ft_printf("tail idx: %d\n", (stack->head + stack->size - 1) % stack->cap);
}

void	print_stats(t_data *data, int mode)
{
	if (mode == 1)
		print_stack(&data->a);
	if (data->bench_mode == 1)
		ft_printf("bench mode: TRUE\n");
	switch(data->algo)
	{
		case ALGO_SIMPLE:
			ft_printf("ALGO: simple\n");
			break;
		case ALGO_INTERMEDIATE:
			ft_printf("ALGO: medium\n");
			break;
		case ALGO_COMPLEX:
			ft_printf("ALGO: complex\n");
			break;
		default:
			ft_printf("ALGO: adaptive\n");
			break;
	}
}