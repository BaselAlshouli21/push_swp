/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <basil42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 22:09:58 by basil42           #+#    #+#             */
/*   Updated: 2026/11/13 22:11:58 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	for (int i = 0; i < stack->size; i++)
		ft_printf("[%d]: [%d]\n", i, stack->buff[i]);
	ft_printf("head: %d\n", stack->head);
	ft_printf("tail: %d\n", (stack->head + stack->size - 1) % stack->cap);
}