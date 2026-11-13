/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <basil42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 20:21:32 by basil42           #+#    #+#             */
/*   Updated: 2026/11/13 21:47:33 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill_stack(t_stack *stack, char **argv, int cap, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * cap);
	if (!arr)
		return (PS_MALLOC_ERROR);
	i = 0;
	while (size > i)
	{
		if (ft_atoi(argv[i], &arr[i]))
		{
			free(arr);
			return (PS_ARGS_ERROR);
		}
		i++;
	}
	init_stack(stack, arr, cap, size);
	return (PS_OK);
}