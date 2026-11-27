/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <balshoul@student.42amman.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 03:21:58 by basil42           #+#    #+#             */
/*   Updated: 2026/11/27 03:33:50 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_llist	*fill(t_llist *node, t_eops op, int n)
{
	while (n > 0)
	{
		node->ops = op;
		node = node->next;
		n--;
	}
	return (node);
}

static t_llist	*write_run(t_llist *node, int a, int b)
{
	int	s;

	s = shared_count(a, b);
	if (a > 0 && b > 0)
		node = fill(node, RR, s);
	else if (a < 0 && b < 0)
		node = fill(node, RRR, s);
	if (a > 0)
		node = fill(node, RA, a - s);
	else if (a < 0)
		node = fill(node, RRA, -a - s);
	if (b > 0)
		node = fill(node, RB, b - s);
	else if (b < 0)
		node = fill(node, RRB, -b - s);
	return (node);
}

t_llist	*rotations(t_lops *l, t_llist *node)
{
	t_llist	*prev;
	t_llist	*end;
	t_llist	*tmp;
	int		net[2];
	int		len;

	if (!is_rot(node->ops) || (node->prev && is_rot(node->prev->ops)))
		return (node);
	len = scan_run(node, &net[0], &net[1]);
	if (new_len(net[0], net[1]) >= len)
		return (node);
	prev = node->prev;
	end = write_run(node, net[0], net[1]);
	while (end && is_rot(end->ops))
	{
		tmp = end->next;
		remove_node(l, end);
		end = tmp;
	}
	if (!prev)
		return (l->head);
	return (prev);
}
