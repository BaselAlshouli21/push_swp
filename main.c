/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 17:49:27 by basil42           #+#    #+#             */
/*   Updated: 2026/11/14 15:46:23 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	error_exit(t_data *data, int e)
{
	free(data->a.buff);
	free(data->b.buff);
	write(2, "Error\n", 6);
	if (e == PS_ARGS_ERROR)
		return (PS_ARGS_ERROR);
	if (e == PS_MALLOC_ERROR)
		return (PS_MALLOC_ERROR);
	return (PS_OK);
}
int	main(int argc, char **argv)
{
	t_data	data;

	argc--;
	argv++;
	
	ft_bzero(&data, sizeof(t_data));
	
	if (parse_flags(&data, &argc, &argv) || argc < 1)
		return (error_exit(&data, PS_ARGS_ERROR));
	
	if (init_stack(&data.a, argc, 0) || init_stack(&data.a, argc, 0))
		return (error_exit(&data, PS_MALLOC_ERROR));

	if (fill_stack(&data.a, argv))
		return (error_exit(&data, PS_ARGS_ERROR));

	print_stack(&data.a);
	return (PS_OK);
}
