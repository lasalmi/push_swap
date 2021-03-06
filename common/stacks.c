/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:10:17 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/02 13:16:17 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

/* Adds a new elements to stack_a and returns a pointer
to that element */

t_node	*ft_create_elem_stack_a(t_utils *utils)
{
	t_node	*new_node;

	new_node = ft_create_node();
	if (!new_node)
	{
		ft_free_lists(utils);
		exit (1);
	}
	ft_add_node_tail(&utils->tail_a, new_node);
	return (new_node);
}

/* Pushes the head element of stack b as 
the new head of stack a and refreshes the counts */

void	ft_push_a(t_utils *utils)
{
	t_node	*to_push;

	to_push = utils->head_b;
	if (!utils->count_b)
		return ;
	ft_delink_head(&utils->head_b);
	if (utils->count_a)
		ft_add_node_head(&utils->head_a, to_push);
	else
	{
		utils->head_a = to_push;
		utils->tail_a = to_push;
		to_push->next = NULL;
	}
	utils->count_a += 1;
	utils->count_b -= 1;
}

/* Pushes the head element of stack a as 
the new head of stack b and refreshes the counts */

void	ft_push_b(t_utils *utils)
{
	t_node	*to_push;

	to_push = utils->head_a;
	if (!utils->count_a)
		return ;
	ft_delink_head(&utils->head_a);
	if (utils->count_b)
		ft_add_node_head(&utils->head_b, to_push);
	else
	{
		utils->head_b = to_push;
		utils->tail_b = to_push;
		to_push->next = NULL;
	}
	utils->count_a -= 1;
	utils->count_b += 1;
	ft_check_list(utils);
}

void	ft_swap_a(t_utils *utils)
{
	if (utils->count_a < 2)
		return ;
	ft_swap_node(utils->head_a, utils->head_a->next);
}

void	ft_swap_b(t_utils *utils)
{
	if (utils->count_b < 2)
		return ;
	ft_swap_node(utils->head_b, utils->head_b->next);
}

void	ft_swap_both(t_utils *utils)
{
	ft_swap_a(utils);
	ft_swap_b(utils);
}

void	ft_rev_rotate_a(t_utils *utils)
{
	t_node	*new_tail;
	t_node	*new_head;

	if (utils->count_a < 2)
		return ;
	new_tail = utils->tail_a->prev;
	new_head = utils->tail_a;
	new_tail->next = NULL;
	new_head->next = utils->head_a;
	new_head->prev = NULL;
	utils->head_a->prev = new_head;
	utils->tail_a->next = utils->head_a;
	utils->head_a = new_head;
	utils->tail_a = new_tail;
}

void	ft_rev_rotate_b(t_utils *utils)
{
	t_node	*temp;

	if (utils->count_b < 2)
		return ;
	temp = utils->tail_b->prev;
	utils->tail_b->next = utils->head_b;
	utils->tail_b->prev->next = NULL;
	utils->head_b->prev = utils->tail_b;
	utils->head_b = utils->tail_b;
	utils->tail_b = temp;
	utils->head_b->prev = NULL;
}

void	ft_rotate_a(t_utils *utils)
{
	t_node	*temp;

	if (utils->count_a < 2)
		return ;
	temp = utils->head_a->next;
	utils->tail_a->next = utils->head_a;
	utils->head_a->prev = utils->tail_a;
	utils->head_a->next = NULL;
	utils->tail_a = utils->head_a;
	temp->prev = NULL;
	utils->head_a = temp;
	ft_check_list(utils);
}

void	ft_rotate_b(t_utils *utils)
{
	t_node	*temp;

	if (utils->count_b < 2)
		return ;
	temp = utils->head_b->next;
	utils->tail_b->next = utils->head_b;
	utils->head_b->prev = utils->tail_b;
	utils->head_b->next = NULL;
	utils->tail_b = utils->head_b;
	temp->prev = NULL;
	utils->head_b = temp;
}

void	ft_rotate_both(t_utils *utils)
{
	ft_rotate_a(utils);
	ft_rotate_b(utils);
}

void	ft_rev_rotate_both(t_utils *utils)
{
	ft_rev_rotate_a(utils);
	ft_rev_rotate_b(utils);
}
