/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_times.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <balshoul@student.42amman.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 22:33:22 by basil42           #+#    #+#             */
/*   Updated: 2026/11/25 22:41:56 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_n(t_data *data, char name, int n)
{
    if (name == 'a')
    {
        while (n--)
            rotate_a(data);
    }
    else
    {
        while (n--)
            rotate_b(data);
    }
}

void	rotate_r_n(t_data *data, int n)
{
	while (n--)
		rotate_r(data);
}

void	reverse_rotate_n(t_data *data, char name, int n)
{
    if (name == 'a')
    {
		while (n--)
			reverse_rotate_a(data);
    }
    else
    {
        while (n--)
			reverse_rotate_b(data);
    }
}
void	reverse_rotate_r_n(t_data *data, int n)
{
	while (n--)
		reverse_rotate_r(data);
}
