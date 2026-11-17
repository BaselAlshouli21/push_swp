/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:48:42 by balshoul          #+#    #+#             */
/*   Updated: 2026/11/17 17:50:17 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	overflow(long n, int sign, char next_digit)
{
	long val;
	val = (n * 10) + (next_digit - '0');
	if (sign == 1 && val > 2147483647)
		return (1);
	if (sign == -1 && (-val) < -2147483648)
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
		return (-1);
	while (ft_isdigit(s[i]))
	{
		if (overflow(n, sign, s[i]))
			return (-1);
		n = n*10 + (s[i++] - '0');
	}
	if (s[i] != '\0')
		return (-1);
	*out = (int)(n * sign);
	return (0);
}