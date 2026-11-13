/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <basil42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 21:00:16 by basil42           #+#    #+#             */
/*   Updated: 2026/11/13 21:33:39 by basil42          ###   ########.fr       */
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
		return (PS_ARGS_ERROR);
	while (ft_isdigit(s[i]))
	{
		if (overflow(n, sign, s[i]))
			return (PS_ARGS_ERROR);
		n = n*10 + (s[i++] - '0');
	}
	if (s[i] != '\0')
		return (PS_ARGS_ERROR);
	*out = (int)(n * sign);
	return (PS_OK);
}