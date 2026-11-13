/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basil42 <basil42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 17:13:12 by basil42           #+#    #+#             */
/*   Updated: 2026/11/13 21:51:55 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

#define INT_MAX 2147483647
#define INT_MIN -2147483648

typedef	enum e_ps_error
{
	PS_OK = 0,
	PS_ARGS_ERROR = -1,
	PS_MALLOC_ERROR = -2
}			t_ps_error;

typedef struct s_stack
{
	int	*buff;
	int head;
	int size;
	int cap;
}				t_stack;

// ***********    push_swp    ***********
double	compute_disorder(int *stack, size_t size);


// *********** circular stack ***********
int		fill_stack(t_stack *stack, char **argv, int cap, int size);

// utils
void	init_stack(t_stack *stack, int *buffer, int cap, int size);


// ***********     parser     ***********

// utils
int		ft_atoi(const char *s, int *out);

#endif