/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 17:13:12 by basil42           #+#    #+#             */
/*   Updated: 2026/11/14 12:32:36 by balshoul         ###   ########.fr       */
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

typedef enum e_algo
{
	ALGO_ADAPTIVE = 0,
	ALGO_SIMPLE,
	ALGO_INTERMEDIATE,
	ALGO_COMPLEX
}			t_algo;

typedef struct s_stack
{
	int	*buff;
	int head;
	int size;
	int cap;
}				t_stack;

typedef	struct s_ops
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int total;
}			t_ops;

typedef struct s_data
{
	t_stack	a;
	t_stack	b;
	t_ops	ops;
	t_algo	algo;
	int		bench_mode;
}			t_data;

// *********** delete_later   ***********
void	print_stack(t_stack *stack);


// ***********    push_swp    ***********
double	compute_disorder(int *stack, size_t size);


// *********** circular stack ***********
int		fill_stack(t_stack *stack, char **argv, int cap, int size);

// utils
void	init_stack(t_stack *stack, int *buffer, int cap, int size);


// ***********     parser     ***********
int		parse_flags(t_data *data, int *argc, char ***argv);

// utils
int		ft_atoi(const char *s, int *out);

#endif