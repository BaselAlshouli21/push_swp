/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 00:11:15 by basil42           #+#    #+#             */
/*   Updated: 2026/11/14 14:19:53 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static void	init_data(t_data *data, const char *str)
{
	data->bytes_written = 0;
	data->s = str;
}

int	ft_printf(const char *str, ...)
{
	t_data	data;

	va_start(data.ap, str);
	init_data(&data, str);
	while (*data.s)
	{
		if (*(data.s) == '%' && *(++data.s))
		{
			if (parse_format(&data))
				return (PARSE_ERROR);
			fix_flags(&data);
			render_format(&data);
		}
		else
			write_buff(&data, data.s++, 1);
	}
	va_end(data.ap);
	return (data.bytes_written);
}
