/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 11:39:23 by balshoul          #+#    #+#             */
/*   Updated: 2026/11/14 19:31:42 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_flag(const char *arg, const char *flag)
{
	return (ft_strncmp(arg, flag, ft_strlen(flag) + 1) == 0);
}

static int	get_algo(const char *arg)
{
	if (is_flag(arg, "--adaptive"))
		return (ALGO_ADAPTIVE);
	if (is_flag(arg, "--simple"))
		return (ALGO_SIMPLE);
	if (is_flag(arg, "--medium"))
		return (ALGO_INTERMEDIATE);
	if (is_flag(arg, "--complex"))
		return (ALGO_COMPLEX);
	return (-1);
}

static int	handle_flag(t_data *data, int *found_algo, const char *arg)
{
	int	algo;

	if (is_flag(arg, "--bench"))
	{
		if (data->bench_mode)
			return (ERR_INVALID_ARGS);
		data->bench_mode = 1;
		return (OK);
	}
	algo = get_algo(arg);
	if (algo < 0 || *found_algo)
		return (ERR_INVALID_ARGS);
	*found_algo = 1;
	data->algo = algo;
	return (OK);
}

int	parse_flags(t_data *data, int *argc, char ***argv)
{
	int	found_algo;

	found_algo = 0;
	data->bench_mode = 0;
	data->algo = ALGO_ADAPTIVE;
	while (*argc > 0 && ft_strncmp(**argv, "--", 2) == 0)
	{
		if (handle_flag(data, &found_algo, **argv))
			return (ERR_INVALID_ARGS);
		(*argv)++;
		(*argc)--;
	}
	return (OK);
}