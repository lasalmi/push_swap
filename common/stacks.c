/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:10:17 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/08 16:56:06 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Adds a new elements to stack_a and returns a pointer
to that element */

t_node	*create_elem_stack_a(t_utils *utils)
{
	t_node	*new_node;

	new_node = create_node();
	if (!new_node)
	{
		free_stacks(utils);
		exit (1);
	}
	add_node_tail(&utils->tail_a, new_node);
	return (new_node);
}

/* Pushes the head element of stack b as 
the new head of stack a and refreshes the counts */

void	push_a(t_utils *utils)
{
	t_node	*to_push;

	to_push = utils->head_b;
	if (!utils->count_b)
		return ;
	delink_head(&utils->head_b);
	if (utils->count_a)
		add_node_head(&utils->head_a, to_push);
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

void	push_b(t_utils *utils)
{
	t_node	*to_push;

	to_push = utils->head_a;
	if (!utils->count_a)
		return ;
	delink_head(&utils->head_a);
	if (utils->count_b)
		add_node_head(&utils->head_b, to_push);
	else
	{
		utils->head_b = to_push;
		utils->tail_b = to_push;
		to_push->next = NULL;
	}
	utils->count_a -= 1;
	utils->count_b += 1;
}
