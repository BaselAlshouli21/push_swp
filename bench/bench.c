/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <balshoul@student.42amman.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 20:34:52 by basil42           #+#    #+#             */
/*   Updated: 2026/11/27 01:47:03 by basil42          ###   ########.fr       */
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

static void	third_line(t_cops cops)
{
	line_start();
	ft_putstr_fd("total_ops:   ", 2);
	ft_putnbr_fd(cops.total, 2);
	ft_putchar_fd('\n', 2);
}

static void	operations(t_cops cops)
{
	line_start();
	ft_putstr_fd("sa:   ", 2);
	ft_putnbr_fd(cops.count[SA], 2);
	ft_putstr_fd("   sb:   ", 2);
	ft_putnbr_fd(cops.count[SB], 2);
	ft_putstr_fd("   ss:   ", 2);
	ft_putnbr_fd(cops.count[SS], 2);
	ft_putstr_fd("   pa:   ", 2);
	ft_putnbr_fd(cops.count[PA], 2);
	ft_putstr_fd("   pb:   ", 2);	
	ft_putnbr_fd(cops.count[PB], 2);
	ft_putchar_fd('\n', 2);
	line_start();
	ft_putstr_fd("ra:   ", 2);
	ft_putnbr_fd(cops.count[RA], 2);
	ft_putstr_fd("   rb:   ", 2);
	ft_putnbr_fd(cops.count[RB], 2);
	ft_putstr_fd("   rr:   ", 2);
	ft_putnbr_fd(cops.count[RR], 2);
	ft_putstr_fd("   rra:   ", 2);
	ft_putnbr_fd(cops.count[RRA], 2);
	ft_putstr_fd("   rrb:   ", 2);
	ft_putnbr_fd(cops.count[RRB], 2);
	ft_putstr_fd("   rrr:   ", 2);
	ft_putnbr_fd(cops.count[RRR], 2);
}

void	bench(t_data *data)
{
	if (data->bench_mode == 0)
		return ;
	first_line(data->disorder);
	second_line(data);
	third_line(data->lops.cops);
	operations(data->lops.cops);
}
