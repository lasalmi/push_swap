/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 08:39:13 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/08 12:22:23 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Allocates a new node and in case
of mallocfail exits */

t_node	*ft_create_node(void)
{
	t_node	*ret;

	ret = (t_node *)malloc(sizeof(t_node));
	if (!ret)
		exit(2);
	ret->next = NULL;
	ret->prev = NULL;
	return (ret);
}

/* Pushes given node as the new tail node
GIVEN NODE MUST BE TAIL! */
void	ft_add_node_tail(t_node **tail, t_node *new_node)
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
void	ft_add_node_head(t_node **head, t_node *new_node)
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

/* Delinks the given tail from the list
and sets the tail as the previous node */
void	ft_delink_tail(t_node **tail)
{
	(*tail)->prev->next = NULL;
	*tail = (*tail)->prev;
}

void	ft_delink_head(t_node **head)
{
	if ((*head)->next)
	{
		(*head)->next->prev = NULL;
		*head = (*head)->next;
	}
	else
		*head = NULL;
}
