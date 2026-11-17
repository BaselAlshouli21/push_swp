/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 20:21:32 by basil42           #+#    #+#             */
/*   Updated: 2026/11/17 17:21:16 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// fills the stack from argv
int	fill_stack(t_stack *stack, char **buff)
{
	int	i;
	int	value;

	i = 0;
	while (buff[i])
	{
		if (stack->size >= stack->cap)
			return (ERR_INVALID_ARGS);
		if (ft_atoi(buff[i], &value) != OK)
			return (ERR_INVALID_ARGS);
		if (search_stack(stack, value) != -1)
			return (ERR_DUP_ARGS);
		stack->buff[(stack->head + stack->size) % stack->cap] = value;
		stack->size++;
		i++;
	}
	return (OK);
}

// returns the index of the smalled number relative to head
int	find_min(t_stack *stack)
{
    int	min_idx;
    int	i;

    if (stack->size == 0)
    	return (-1);
    i = 1;
    min_idx = 0;
    while (i < stack->size)
    {
        if (stack_at(stack, min_idx) > stack_at(stack, i))
        	min_idx = i;
        i++;
    }
    return (min_idx);
}