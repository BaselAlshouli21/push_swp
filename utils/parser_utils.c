/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 21:00:16 by basil42           #+#    #+#             */
/*   Updated: 2026/11/17 18:11:23 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_flag(const char *arg, const char *flag)
{
	return (ft_strncmp(arg, flag, ft_strlen(flag) + 1) == 0);
}

int	get_algo(const char *arg)
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

int	handle_flag(t_data *data, int *found_algo, const char *arg)
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

void	free_split(char **split)
{
	int	i;
	
	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}