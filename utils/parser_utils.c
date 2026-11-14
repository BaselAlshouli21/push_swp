/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 21:00:16 by basil42           #+#    #+#             */
/*   Updated: 2026/11/14 19:31:42 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	overflow(long n, int sign, char next_digit)
{
	long val;
	val = (n * 10) + (next_digit - '0');
	if (sign == 1 && val > INT_MAX)
		return (1);
	if (sign == -1 && (-val) < INT_MIN)
		return (1);
	return (0);
}

static int	parse_sign(const char *s, int *i)
{
	int sign;

	sign = 1;
	while (ft_isspace(s[*i]))
		(*i)++;
	if (s[*i] == '-' || s[*i] == '+')
	{
		if (s[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi(const char *s, int *out)
{
	long	n;
	int		i;
	int		sign;

	i = 0;
	n = 0;
	sign = parse_sign(s, &i);
	if (!ft_isdigit(s[i]))
		return (ERR_INVALID_ARGS);
	while (ft_isdigit(s[i]))
	{
		if (overflow(n, sign, s[i]))
			return (ERR_INVALID_ARGS);
		n = n*10 + (s[i++] - '0');
	}
	if (s[i] != '\0')
		return (ERR_INVALID_ARGS);
	*out = (int)(n * sign);
	return (OK);
}