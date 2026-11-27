/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <balshoul@student.42amman.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 03:35:51 by basil42           #+#    #+#             */
/*   Updated: 2026/11/27 03:38:26 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_rot(t_eops op)
{
	return (op >= RA && op <= RRR);
}

static void	add_net(t_eops op, int *a, int *b)
{
	if (op == RA || op == RR)
		(*a)++;
	if (op == RB || op == RR)
		(*b)++;
	if (op == RRA || op == RRR)
		(*a)--;
	if (op == RRB || op == RRR)
		(*b)--;
}

int	scan_run(t_llist *node, int *a, int *b)
{
	int	len;

	len = 0;
	*a = 0;
	*b = 0;
	while (node && is_rot(node->ops))
	{
		add_net(node->ops, a, b);
		len++;
		node = node->next;
	}
	return (len);
}

int	new_len(int a, int b)
{
	if ((a >= 0 && b >= 0) || (a <= 0 && b <= 0))
		return (biggest(absolute(a), absolute(b)));
	return (absolute(a) + absolute(b));
}

int	shared_count(int a, int b)
{
	if (a > 0 && b > 0)
	{
		if (a < b)
			return (a);
		return (b);
	}
	if (a < 0 && b < 0)
	{
		if (a > b)
			return (-a);
		return (-b);
	}
	return (0);
}
