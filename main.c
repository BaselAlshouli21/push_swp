/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 17:49:27 by basil42           #+#    #+#             */
/*   Updated: 2026/11/26 22:15:44 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	error_exit(t_data *data, int e)
{
	free(data->a.buff);
	free(data->b.buff);
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

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc-- < 2)
		return (1);
	argv++;
	
	ft_bzero(&data, sizeof(t_data));
	if (parse_flags(&data, &argc, &argv) || argc < 1)
		return (error_exit(&data, ERR_INVALID_ARGS));
	if (expand_args(&argc, argv))
		return (error_exit(&data, ERR_INVALID_ARGS));
	if (init_stack(&data.a, argc, 0) || init_stack(&data.b, argc, 0))
		return (error_exit(&data, ERR_MALLOC));
	if (parse_args(&data.a, argv))
		return (error_exit(&data, ERR_INVALID_ARGS));
	if (sort_dispatcher(&data))
		return (error_exit(&data, ERR_SORTED_STACK));
	bench(&data);
	return (OK);
}
