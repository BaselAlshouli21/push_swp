/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pairs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <balshoul@student.42amman.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 02:08:50 by basil42           #+#    #+#             */
/*   Updated: 2026/11/27 03:27:31 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_swap(t_eops op)
{
	return (op == SA || op == SB || op == SS);
}

static int	pair_swap(t_lops *l, t_llist *node)
{
	t_llist	*next;

	next = node->next;
	if (next && (node->ops == next->ops) && is_swap(node->ops))
	{
		remove_node(l, next);
		remove_node(l, node);
		return (1);
	}
	return (0);
}

static int	push_pair(t_lops *l, t_llist *node)
{
	t_llist *next;
	
	next = node->next;
	if (!next)
		return (0);
	if ((node->ops == PA && next->ops == PB)
			|| (node->ops == PB && next->ops == PA))
	{
		remove_node(l, next);
		remove_node(l, node);
		return (1);
	}
	return (0);
}

static int	optimize_swap(t_lops *l, t_llist *node)
{
	t_llist	*next;

	next = node->next;
	if (!next)
		return (0);
	if ((node->ops == SA && next->ops == SB)
			|| (node->ops == SB && next->ops == SA))
	{
		node->ops = SS;
		remove_node(l, next);
		return (1);
	}
	return (0);
}

t_llist	*pairs(t_lops *l, t_llist *node)
{
	t_llist	*prev;

	prev = node->prev;
	if (pair_swap(l, node) || push_pair(l, node) || optimize_swap(l, node))
	{
		if (!prev)
			return (l->head);
		return (prev);
	}
	return (node);
}
