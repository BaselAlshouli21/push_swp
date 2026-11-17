/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 17:13:12 by basil42           #+#    #+#             */
/*   Updated: 2026/11/17 00:14:14 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

#define INT_MAX 2147483647
#define INT_MIN -2147483648

typedef	enum e_error
{
	OK = 0,
	ERR_INVALID_ARGS = -1,
	ERR_MALLOC = -2,
	ERR_DUP_ARGS = -3,
	ERR_SORTED_STACK = -4
}			t_error;

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
	double	disorder;
}			t_data;

// *********** delete_later   ***********
void	print_arr(t_stack *stack, char name);
void	print_stats(t_data *data, int mode);
void	print_stacks(t_data *data);


// ***********    push_swp    ***********


// utils
double	compute_disorder(int *stack, size_t size);
void	print_disorder(t_data *data);


// *********** circular stack ***********
int		fill_stack(t_stack *stack, char **buff);

// utils
int		init_stack(t_stack *stack, int cap, int size);
int		search_stack(t_stack *stack, int n);
void	set_stack(t_stack *stack, int n);
int		stack_at(t_stack *stack, int i);
int		get_tail(t_stack *stack);


// ***********     parser     ***********
int		parse_flags(t_data *data, int *argc, char ***argv);

// utils
int		ft_atoi(const char *s, int *out);


// ***********   operations   ***********
// swap
void	swap_a(t_data *data);
void	swap_b(t_data *data);
void	swap_s(t_data *data);

// push
void	push_a(t_data *data);
void	push_b(t_data *data);

#endif