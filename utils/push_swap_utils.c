/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <basil42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 19:00:22 by basil42           #+#    #+#             */
/*   Updated: 2026/11/13 19:58:47 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(int *stack, size_t size)
{
	int mistakes;
	int total_pairs;
	size_t	j;
	size_t	i;

	if (size < 2)
		return (0.0);
	total_pairs = 0;
	mistakes = 0;
	i = 0;
	while (size > i)
	{
		j = i + 1;
		while (size > j)
		{
			total_pairs++;
			if (stack[i] > stack[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return ((double)mistakes / (double)total_pairs);
}