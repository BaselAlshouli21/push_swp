/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 17:49:27 by basil42           #+#    #+#             */
/*   Updated: 2026/11/27 03:50:49 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (data.malloc_err)
		return (error_exit(&data, ERR_MALLOC));
	optimizer(&data);
	recount_ops(&data.lops);
	print_ops(&data.lops);
	ft_putnbr_fd(data.lops.cops.total, 2);
	free_mal(&data);
	return (OK);
}
