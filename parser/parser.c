/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 11:39:23 by balshoul          #+#    #+#             */
/*   Updated: 2026/11/17 18:10:50 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(const char *str, char sep)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != sep && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*str == sep)
			in_word = 0;
		str++;
	}
	return (count);
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

int	expand_args(int *argc, char **argv)
{
	int	i;
	int	words;

	i = 0;
	while (argv[i])
	{
		words = count_words(argv[i], ' ');
		if (words == 0)
			return (ERR_INVALID_ARGS);
		*argc += words - 1;
		i++;
	}
	return (OK);
}

int	parse_args(t_stack *stack, char **argv)
{
	char	**tokens;
	int		status;
	int		i;

	i = 0;
	while (argv[i])
	{
		tokens = ft_split(argv[i], ' ');
		if (!tokens || !tokens[0])
		{
			free_split(tokens);
			return (ERR_INVALID_ARGS);
		}
		status = fill_stack(stack, tokens);
		free_split(tokens);
		if (status != OK)
			return (status);
		i++;
	}
	return (OK);
}