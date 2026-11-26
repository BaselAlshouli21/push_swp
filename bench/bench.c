/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <balshoul@student.42amman.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 20:34:52 by basil42           #+#    #+#             */
/*   Updated: 2026/11/26 22:03:23 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	line_start()
{
	ft_putstr_fd("[bench] ", 2);
}

static void	first_line(double disorder)
{
	int	scaled;
	int	whole;
	int	frac;

	scaled = (int)(disorder * 10000.0 + 0.5);
	whole = scaled / 100;
	frac = scaled % 100;
	line_start();
	ft_putstr_fd("disorder:   ", 2);
	ft_putnbr_fd(whole, 2);
	ft_putstr_fd(".", 2);
	ft_putnbr_fd(frac, 2);
	ft_putstr_fd("%\n", 2);
}

static void	second_line(t_data *data)
{
	line_start();
	ft_putstr_fd("strategy:   ", 2);
	if (data->adaptive)
	{
		ft_putstr_fd("Adaptive / ", 2);
		ft_putstr_fd(data->complexity, 2);
	}
	else if (data->algo == ALGO_SIMPLE)
	{
		ft_putstr_fd("Simple / ", 2);
		ft_putstr_fd(SIMPLE, 2);
	}
	else if (data->algo == ALGO_INTERMEDIATE)
	{
		ft_putstr_fd("Medium / ", 2);
		ft_putstr_fd(MEDIUM, 2);
	}
	else if (data->algo == ALGO_COMPLEX)
	{
		ft_putstr_fd("Complex / ", 2);
		ft_putstr_fd(COMPLEX, 2);
	}
	ft_putchar_fd('\n', 2);
}

static void	third_line(t_ops ops)
{
	line_start();
	ft_putstr_fd("total_ops:   ", 2);
	ft_putnbr_fd(ops.total, 2);
	ft_putchar_fd('\n', 2);
}

static void	operations(t_ops ops)
{
	line_start();
	ft_putstr_fd("sa:   ", 2);
	ft_putnbr_fd(ops.sa, 2);
	ft_putstr_fd("   sb:   ", 2);
	ft_putnbr_fd(ops.sb, 2);
	ft_putstr_fd("   ss:   ", 2);
	ft_putnbr_fd(ops.ss, 0);
	ft_putstr_fd("   pa:   ", 2);
	ft_putnbr_fd(ops.pa, 2);
	ft_putstr_fd("   pb:   ", 2);	
	ft_putnbr_fd(ops.pb, 2);
	ft_putchar_fd('\n', 2);
	line_start();
	ft_putstr_fd("ra:   ", 2);
	ft_putnbr_fd(ops.ra, 2);
	ft_putstr_fd("   rb:   ", 2);
	ft_putnbr_fd(ops.rb, 2);
	ft_putstr_fd("   rr:   ", 2);
	ft_putnbr_fd(ops.rr, 2);
	ft_putstr_fd("   rra:   ", 2);
	ft_putnbr_fd(ops.rra, 2);
	ft_putstr_fd("   rrb:   ", 2);
	ft_putnbr_fd(ops.rrb, 2);
	ft_putstr_fd("   rrr:   ", 2);
	ft_putnbr_fd(ops.rrr, 2);
}

void	bench(t_data *data)
{
	if (data->bench_mode == 0)
		return ;
	first_line(data->disorder);
	second_line(data);
	third_line(data->ops);
	operations(data->ops);
}
