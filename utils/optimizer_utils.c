/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <balshoul@student.42amman.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 01:04:57 by basil42           #+#    #+#             */
/*   Updated: 2026/11/27 03:48:31 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_op(t_lops *l, t_eops op)
{
	t_llist	*node;

	node = malloc(sizeof(t_llist));
	if (!node)
		return (ERR_MALLOC);
	node->ops = op;
	node->next = NULL;
	node->prev = l->tail;
	if (l->tail)
		l->tail->next = node;
	else
		l->head = node;
	l->tail = node;
	return (OK);
}

void	remove_node(t_lops *l, t_llist *node)
{
	if (!l || !node)
		return ;
	if (node->prev)
		node->prev->next = node->next;
	else
		l->head = node->next;
	if (node->next)
		node->next->prev = node->prev;
	else
		l->tail = node->prev;
	free(node);
}

void	recount_ops(t_lops *l)
{
	t_llist *cur;
	int		i;

	i = 0;
	while (i < OP_COUNT)
		l->cops.count[i++] = 0;
	l->cops.total = 0;
	cur = l->head;
	while (cur)
	{
		l->cops.count[cur->ops]++;
		l->cops.total++;
		cur = cur->next;
	}
}

void	print_ops(t_lops *l)
{
	t_llist *cur;

	cur = l->head;
	const char	*names[OP_COUNT] = {"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};
	
	while (cur)
	{
		ft_printf("%s\n", names[cur->ops]);
		cur = cur->next;
	}
	recount_ops(l);
}
