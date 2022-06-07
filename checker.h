/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 02:49:30 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/07 17:41:44 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "./libft/libft.h"
typedef struct s_node {
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_utils {
	struct s_node	*head_a;
	struct s_node	*tail_a;
	size_t			count_a;
	struct s_node	*head_b;
	struct s_node	*tail_b;
	size_t			count_b;
}	t_utils;

t_node	*ft_createnode(void);
void	ft_swapnode(t_node *node, t_node *node2);
void	ft_printlist(t_utils utils);
void	ft_add_node_tail(t_node **tail, t_node *new_node);
void	ft_add_node_head(t_node **head, t_node *new_node);
t_node	*ft_create_elem_stack_a(t_utils *utils);
void	ft_delink_tail(t_node **tail);
void 	ft_push_a(t_utils *utils);
void 	ft_push_b(t_utils *utils);
void 	ft_swap_a(t_utils *utils);
void 	ft_swap_b(t_utils *utils);
void 	ft_swap_both(t_utils *utils);
void	ft_delink_head(t_node **head);
void	ft_initutils(t_utils *utils);
void	ft_rotate_a(t_utils *utils);
void 	ft_rev_rotate_b(t_utils *utils);
void 	ft_rev_rotate_a(t_utils *utils);
void	ft_rotate_a(t_utils *utils);
void	ft_rotate_both(t_utils *utils);
#endif