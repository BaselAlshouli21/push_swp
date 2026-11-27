/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <balshoul@student.42amman.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 22:39:54 by basil42           #+#    #+#             */
/*   Updated: 2026/11/27 03:41:29 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimizer(t_data *data)
{
	t_llist *next;
	t_llist	*cur;

	cur = data->lops.head;
	while (cur)
	{
		next = pairs(&data->lops, cur);
		if (next != cur)
		{
			cur = next;
			continue ;
		}
		next = rotations(&data->lops, cur);
		if (next != cur)
		{
			cur = next;
			continue ;
		}
		cur = cur->next;
	}
}
