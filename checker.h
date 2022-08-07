/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 02:49:30 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/07 13:47:10 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define UNDER_20 1
# define UNDER_50 1
# define UNDER_150 1
# define OVER_150 1
# include "./libft/libft.h"
# include <limits.h>

typedef struct s_node {
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef enum e_pw_caller {
	CHECKER,
	PUSH_SWAP,
	PRINT,
	SANDBOX,
	INITIALIZER
}	t_pw_caller;

typedef struct s_utils {
	int				input_count;
	struct s_node	*head_a;
	struct s_node	*tail_a;
	size_t			count_a;
	struct s_node	*head_b;
	struct s_node	*tail_b;
	size_t			count_b;
	size_t			instr_count;
	int				*sorted;
	t_pw_caller		caller;
	char			*file;
}	t_utils;

typedef struct s_instructions {
	int		*inst_array;
	size_t	memthreshold;
	size_t	count;
}	t_instructions;

typedef struct s_chunk {
	int		start;
	int		end;
	uint8_t	processed;
	uint8_t	sorted;
}	t_chunk;

typedef struct s_solver {
	struct s_chunk	*chunks;
	size_t			chunk_amount;
}	t_solver;

typedef struct s_target {
	uint8_t	processed;
	int		rotate_target;
	int		rev_target;
	int		rotate_cost;
	int		rev_rot_cost;
	int		rotate_pair;
	int		rot_pair_cost;
	int		rev_pair;
	int		rev_pair_cost;
}	t_ints;

typedef struct s_cost {
	uint8_t	found;
	int		target;
	size_t	rotate_cost;
	size_t	rev_cost;
}	t_cost;

typedef struct s_pair {
	struct s_cost	stack_a;
	struct s_cost	stack_b;
	size_t			total_cost;
	int				*instructions;
}	t_pair;

typedef enum e_type {
	NOT_FOUND,
	ROTREV,
	REVROT,
	ROTATE,
	REV,
	__UNUSED
}	t_type;

typedef void	(*t_func)(t_utils*);

t_node	*ft_create_node(void);
// void	ft_swap_node(t_node *node, t_node *node2);
void	ft_print_list(t_utils utils);
void	ft_add_node_tail(t_node **tail, t_node *new_node);
void	ft_add_node_head(t_node **head, t_node *new_node);
t_node	*ft_create_elem_stack_a(t_utils *utils);
void	ft_delink_tail(t_node **tail);
void	ft_push_a(t_utils *utils);
void	ft_push_b(t_utils *utils);
void	ft_swap_a(t_utils *utils);
void	ft_swap_b(t_utils *utils);
void	ft_swap_both(t_utils *utils);
void	ft_rotate_a(t_utils *utils);
void	ft_rotate_b(t_utils *utils);
void	ft_rev_rotate_b(t_utils *utils);
void	ft_rev_rotate_a(t_utils *utils);
void	ft_rotate_a(t_utils *utils);
void	ft_rotate_both(t_utils *utils);
void	ft_rev_rotate_both(t_utils *utils);
void	ft_delink_head(t_node **head);
void	ft_initialize_utils(t_utils *utils);
void	ft_init_instructions(t_instructions *instructions);
void	ft_read_values(t_utils *utils, char **argv, int argc);
void	ft_error(void);
void	ft_free_lists(t_utils *utils);
void	ft_pw_dispatcher(t_utils *utils, int func_index);
void	ft_getchunks(t_utils *utils, t_solver *solver);
int		ft_findslotb(int nb, t_node *head);
void	ft_copy_node(t_node *dst, t_node *src);
t_ints	ft_find_closest_a(t_chunk *chunk, t_node *head, t_node *tail);
int		ft_countcost_a(int value_to_find, t_utils *utils);
int		ft_countcost_b(int value_to_find, t_utils *utils);
int		ft_count_chunk_cost(t_utils	*original, t_chunk *chunk);
void	ft_loop_dispatcher(size_t n, t_utils *utils, int instruction);
int		ft_cheapest_chunk(t_utils *original, t_solver *solver);
void	ft_check_list(t_utils *utils);
void	ft_init_ints(t_ints *target);
void	ft_get_ints_costs(t_ints *target, t_utils *utils);
t_pair	ft_findpair(t_chunk *chunk, t_utils *utils);
size_t	ft_returngreater(size_t a, size_t b);
t_type	ft_findtype(t_pair *pair);
void	ft_generate_instructions(t_pair *pair);
t_cost	ft_find_biggest(t_node *head, int stack_size);
int		ft_is_correct(t_utils *utils);
void	ft_solver_large(t_utils *utils);
size_t	ft_push_b_all(t_utils *utils);
void	ft_output(t_utils *utils, int instruction);
int		in_order(t_utils *utils);
void	ft_sort_small(t_utils *utils);
void	ft_count_nodes(t_utils *utils);
int		ft_find_smallest(t_node *head);
void	preliminary_stack_sort(t_utils *utils);
void	mallocfail(t_utils *utils);
size_t	count_nodes(t_node *head);
void	ft_exec_instructions(t_utils *utils, t_instructions *instr);
void	ft_save_instruction(t_instructions *instr, char *line);
void	ft_copy_utils(t_utils *dst, t_utils *src);
void	ft_initialize_target(t_cost	*cost);
int		ft_ismember(t_chunk *chunk, int value);
t_cost	ft_find_pair_for_b(int stack_b, t_node *head, int list_size);
t_cost	ft_count_cost(int member, int i, int stack_size);
int		ft_total_cost_smaller(size_t total_cost, \
int b_value, int i, t_utils utils);
size_t	ft_total_cost_move(t_cost target_a, t_cost target_b);
void	ft_sortvalues(t_utils *utils);
void	move_pair(t_utils *utils, t_pair *pair, size_t *cost);
void	ft_sort_stack_a(t_utils *utils);
t_type	ft_samedirection(t_cost a, t_cost b, size_t cost);
t_type	ft_iscombination(t_cost a, t_cost b, size_t cost);
void	ft_gen_rotate(t_pair *pair);
void	ft_gen_rev(t_pair *pair);
void	ft_gen_rotrev(t_pair *pair);
void	ft_gen_revrot(t_pair *pair);
#endif