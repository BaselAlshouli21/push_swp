/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 20:21:32 by basil42           #+#    #+#             */
/*   Updated: 2026/11/14 19:31:59 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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