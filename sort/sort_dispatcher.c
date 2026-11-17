/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dispatcher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:32:18 by balshoul          #+#    #+#             */
/*   Updated: 2026/11/16 21:13:34 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_dispatcher(t_data *data)
{
    
	if (data->disorder == 0.0 && data->bench_mode == 1)
        ft_printf("bench-mode"); // bench_func
    else if (data->disorder == 0.0)
    	return (ERR_SORTED_STACK);
    
    if (data->algo == ALGO_SIMPLE)
    	sort_simple(data);
    else if (data->algo == ALGO_INTERMEDIATE)
    	sort_medium(data);
    else if (data->algo == ALGO_COMPLEX)
    	sort_complex(data);
    else if (data->algo == ALGO_ADAPTIVE)
    	sort_adaptive(data);
    return (OK);
}