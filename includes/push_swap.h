/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 17:13:12 by basil42           #+#    #+#             */
/*   Updated: 2026/11/27 03:48:40 by basil42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

#define OPS_MAX 12000

# define INT_MAX 2147483647

# define SIMPLE "O(n^2)"
# define MEDIUM "O(n\xe2\x88\x9an)"
# define COMPLEX "O(n log n)"


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

typedef enum e_eops
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	OP_COUNT
}			t_eops;

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

typedef struct s_llist
{
	struct s_llist	*next;
	struct s_llist	*prev;
	t_eops			ops;
}			t_llist;

typedef struct s_cops
{
	int count[OP_COUNT];
	int total;
}			t_cops;

typedef struct s_lops 
{
	t_llist	*head;
	t_llist	*tail;
	t_cops	cops;
}			t_lops;

typedef struct s_data
{
	t_stack	a;
	t_stack	b;
	t_lops	lops;
	t_algo	algo;
	double	disorder;
	char	*complexity;
	int		bench_mode;
	int		adaptive;
	int		malloc_err;
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
int		sort_dispatcher(t_data *data);
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
void	try_move(int a, int b, int *best, t_bmove *best_mv);
void	reverse_rotate_a(t_data *data);
void	reverse_rotate_b(t_data *data);
void	reverse_rotate_r(t_data *data);

// n_times
void	reverse_rotate_n(t_data *data, char name, int n);
void	rotate_n(t_data *data, char name, int n);
void	reverse_rotate_r_n(t_data *data, int n);
void	rotate_r_n(t_data *data, int n);

// bench
void	bench(t_data *data);


// ***********   optimizer   ***********
int		scan_run(t_llist *node, int *a, int *b);
t_llist *rotations(t_lops *l, t_llist *node);
t_llist	*pairs(t_lops *l, t_llist *node);
int		shared_count(int a, int b);
void	optimizer(t_data *data);
int		new_len(int a, int b);
int		is_rot(t_eops op);


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
int		smallest(int a, int b);
int		biggest(int a, int b);
int		absolute(int n);

// stack
int		init_stack(t_stack *stack, int cap, int size);
int		search_stack(t_stack *stack, int n);
void	set_stack(t_stack *stack, int n);
int		stack_at(t_stack *stack, int i);
int		get_tail(t_stack *stack);

// error_exit
int		error_exit(t_data *data, t_error e);
void	free_mal(t_data *data);

// optimizer
void	remove_node(t_lops *l, t_llist *node);
int		add_op(t_lops *l, t_eops op);
void	recount_ops(t_lops *l);
void	print_ops(t_lops *l);

#endif
