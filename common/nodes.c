/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 08:39:13 by lasalmi           #+#    #+#             */
/*   Updated: 2022/07/13 12:51:48 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

t_node	*ft_copylist(t_node *head)
{
	t_node	*dst_head;
	t_node	*current;

	if (!head)
		return (NULL);
	dst_head = ft_createnode();
	current = dst_head;
	while (current)
	{
		ft_copynode(current, head);
		if (head->next)
		{
			current->next = ft_createnode();
			if (!current->next)
				break ;
			current->next->prev = current;
		}
		current = current->next;
		head = head->next;
	}
	return (dst_head);
}

void	ft_copynode(t_node *dst, t_node *src)
{
	dst->value = src->value;
}

size_t	countnodes(t_node *head)
{
	size_t	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

/* Allocates a new node and in case
of mallocfail exits */

t_node	*ft_createnode(void)
{
	t_node	*ret;

	ret = (t_node *)malloc(sizeof(t_node));
	if (!ret)
		return (NULL);
	ret->next = NULL;
	ret->prev = NULL;
	return (ret);
}

/* Swaps the VALUES of two nodes */
void	ft_swapnode(t_node *node, t_node *node2)
{
	ft_swap(&node->value, &node2->value);
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
