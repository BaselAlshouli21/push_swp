/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 13:10:50 by balshoul          #+#    #+#             */
/*   Updated: 2026/11/17 13:38:55 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_data *data)
{
    int	top;
    int	mid;
    int	bot;
    
    if (data->a.size < 3)
    	return ;
    top = stack_at(&data->a, 0);
    mid = stack_at(&data->a, 1);
    bot = stack_at(&data->a, 2);
	if (top > mid && top > bot)
    	rotate_a(data);
    else if (mid > top && mid > bot)
    	reverse_rotate_a(data);
    top = stack_at(&data->a, 0);
    mid = stack_at(&data->a, 1);
    if (top > mid)
    	swap_a(data);
}