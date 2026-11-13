/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <basil42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 17:49:27 by basil42           #+#    #+#             */
/*   Updated: 2026/11/13 22:06:26 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;

	argc--;
	argv++;
	if (fill_stack(&stack, argv, argc, argc))
		return (PS_ARGS_ERROR);

	for (int i = 0; i < stack.size; i++)
		ft_printf("[%d]: [%d]\n", i, stack.buff[i]);
	ft_printf("head: %d\n", stack.head);
	ft_printf("tail: %d\n", (stack.head + stack.size - 1) % stack.cap);
	return (0);
}
