/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 17:13:12 by basil42           #+#    #+#             */
/*   Updated: 2026/11/25 23:32:03 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

# define INT_MAX 2147483647

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
	ALGO_ADAPTIVE,
	ALGO_SIMPLE,
	ALGO_INTERMEDIATE,
	ALGO_COMPLEX
}			t_algo;

typedef enum e_rotations
{
	BOTH_R,
	BOTH_RR,
	AR_BRR,
	ARR_BR
}			t_rotations;

typedef struct s_bmove
{
	t_rotations	r;
	int			a_move;
	int			b_move;
	int			cost;
	
}			t_bmove;

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
void	print_stack(t_stack *stack, char name);
void	print_stats(t_data *data, int mode);
void	print_stacks(t_data *data);


// *********** circular stack ***********
int		fill_stack(t_stack *stack, char **buff);
int		find_min(t_stack *stack);
int		find_max(t_stack *s);

// ***********     parser     ***********
int		parse_flags(t_data *data, int *argc, char ***argv);
int		parse_args(t_stack *stack, char **argv);
int		expand_args(int *argc, char **argv);


// ***********      sort      ***********
void	selection_sort(t_data *data);
void	chunk_sort(t_data *data);
void	turk_sort(t_data *data);

// ***********   operations   ***********
// swap
void	swap_a(t_data *data);
void	swap_b(t_data *data);
void	swap_s(t_data *data);

// push
void	push_a(t_data *data);
void	push_b(t_data *data);

// rotate
void	rotate_a(t_data *data);
void	rotate_b(t_data *data);
void	rotate_r(t_data *data);

// reverse rotate
void	reverse_rotate_a(t_data *data);
void	reverse_rotate_b(t_data *data);
void	reverse_rotate_r(t_data *data);
void	try_move(int a, int b, int *best, t_bmove *best_mv);

// n_times
void	reverse_rotate_n(t_data *data, char name, int n);
void	rotate_n(t_data *data, char name, int n);
void	reverse_rotate_r_n(t_data *data, int n);
void	rotate_r_n(t_data *data, int n);


// ***********   utilities   ***********
// sort
int		smallest_biggest(t_stack *a, int val, int *min_idx);
t_bmove	calculate_cost(t_data *data, int a_idx, int b_idx);
void	sort_three(t_data *data);

// parser
int		handle_flag(t_data *data, int *found_algo, const char *arg);
int		is_flag(const char *arg, const char *flag);
int		get_algo(const char *arg);
void	free_split(char **split);

// push_swp
double	compute_disorder(int *stack, size_t size);
void	print_disorder(t_data *data);
int		absolute(int n);
int		biggest(int a, int b);
int		smallest(int a, int b);

// stack
int		init_stack(t_stack *stack, int cap, int size);
int		search_stack(t_stack *stack, int n);
void	set_stack(t_stack *stack, int n);
int		stack_at(t_stack *stack, int i);
int		get_tail(t_stack *stack);


#endif
