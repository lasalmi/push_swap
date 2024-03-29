/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 08:39:13 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/08 19:06:37 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Allocates a new node and in case
of mallocfail exits */

t_node	*create_node(void)
{
	t_node	*ret;

	ret = (t_node *)malloc(sizeof(t_node));
	if (!ret)
		return (ret);
	ret->next = NULL;
	ret->prev = NULL;
	return (ret);
}

/* Pushes given node as the new tail node
GIVEN NODE MUST BE TAIL! */
void	add_node_tail(t_node **tail, t_node *new_node)
{
	if ((*tail)->next)
	{
		ft_putstr_fd("List error, given node was not tail!", 2);
		exit (1);
	}
	new_node->next = NULL;
	new_node->prev = *tail;
	(*tail)->next = new_node;
	*tail = new_node;
}

/* Pushes given node as the new head node
GIVEN NODE MUST BE HEAD! */
void	add_node_head(t_node **head, t_node *new_node)
{
	if ((*head)->prev)
	{
		ft_putstr_fd("List error, given node was not head!", 2);
		exit (1);
	}
	new_node->prev = NULL;
	new_node->next = *head;
	(*head)->prev = new_node;
	*head = new_node;
}

void	delink_head(t_node **head)
{
	if ((*head)->next)
	{
		(*head)->next->prev = NULL;
		*head = (*head)->next;
	}
	else
		*head = NULL;
}
