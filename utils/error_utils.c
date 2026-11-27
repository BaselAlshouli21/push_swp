/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <balshoul@student.42amman.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 01:24:38 by basil42           #+#    #+#             */
/*   Updated: 2026/11/27 01:43:09 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_mal(t_data *data)
{
	t_lops	*l;
	t_llist	*cur;
	t_llist	*next;

	l = &data->lops;
	if (!l)
		return ;
	cur = l->head;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	l->head = NULL;
	l->tail = NULL;
	free(data->a.buff);
	free(data->b.buff);
}

int	error_exit(t_data *data, t_error e)
{
	free_mal(data);
	if (e == ERR_INVALID_ARGS)
	{
		return (ERR_INVALID_ARGS);
		write(2, "Error\n", 6);
	}
	if (e == ERR_MALLOC)
	{
		return (ERR_MALLOC);
		write(2, "Error\n", 6);
	}
	if (e == ERR_SORTED_STACK)
		return (ERR_SORTED_STACK);
	return (OK);
}
