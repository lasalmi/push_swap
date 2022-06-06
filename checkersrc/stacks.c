/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:10:17 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/06 17:38:28 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

/* Adds a new elements to stack_a and returns a pointer
to that element */

t_node	*ft_create_elem_stack_a(t_utils *utils)
{
	t_node *new_node;

	new_node = ft_createnode();
	ft_add_node_tail(&utils->tail_a, new_node);
	return (new_node);
}

/* Pushes the head element of stack b as 
the new head of stack a and refreshes the counts */

void ft_push_a(t_utils *utils)
{
	t_node *to_push;

	to_push = utils->head_b;
	if (!utils->count_b)
		return ;
	ft_delink_head(&utils->head_b);
	if (utils->count_a)
		ft_add_node_head(&utils->head_a, to_push);
	else
	{
		utils->head_a = to_push;
		to_push->next = NULL;
	}
	utils->count_a += 1;
	utils->count_b -= 1;
}

/* Pushes the head element of stack a as 
the new head of stack b and refreshes the counts */

void ft_push_b(t_utils *utils)
{
	t_node *to_push;

	to_push = utils->head_a;
	if (!utils->count_a)
		return ;
	ft_delink_head(&utils->head_a);
	if (utils->count_b)
		ft_add_node_head(&utils->head_b, to_push);
	else
	{
		utils->head_b = to_push;
		to_push->next = NULL;
	}
	utils->count_a -= 1;
	utils->count_b += 1;
}

void ft_swap_a(t_utils *utils)
{
	ft_swapnode(utils->head_a, utils->head_a->next);
}

void ft_swap_b(t_utils *utils)
{
	ft_swapnode(utils->head_b, utils->head_b->next);
}