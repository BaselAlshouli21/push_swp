/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <basil42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 20:07:31 by basil42           #+#    #+#             */
/*   Updated: 2026/11/13 20:20:37 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack, int *buffer, int cap, int size)
{
	stack->buff = buffer;
	stack->cap = cap;
	stack->size = size;
	stack->head = 0;
}