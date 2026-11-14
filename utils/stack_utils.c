/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 20:07:31 by basil42           #+#    #+#             */
/*   Updated: 2026/11/14 20:03:15 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// initalize the stack
int	init_stack(t_stack *stack, int cap, int size)
{
	stack->buff = malloc(sizeof(int) * cap);
	if (!stack->buff)
		return (ERR_MALLOC);
	stack->cap = cap;
	stack->size = size;
	stack->head = 0;
	return (OK);
}

// gets tail index
int	get_tail(t_stack *stack)
{
	if (stack->size == 0)
		return (-1);
	return ((stack->head + stack->size - 1) % stack->cap);
}

// set all elements in the stack to n from head to tail
void	set_stack(t_stack *stack, int n)
{
	int	i;
	
	i = 0;
	while (stack->cap > i)
		stack->buff[i++] = n;
}

// search stack
int		search_stack(t_stack *stack, int n)
{
	int	i;
	int	idx;

	i = 0;
	while (stack->size > i)
	{
		idx = (stack->head + i) % stack->cap;
		if (stack->buff[idx] == n)
			return (i);
		i++;
	}
	return (-1);
}