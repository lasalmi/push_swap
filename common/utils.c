/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:28:32 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/04 13:20:12 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

t_node	*ft_copy_list(t_node *head)
{
	t_node	*dst_head;
	t_node	*current;

	if (!head)
		return (NULL);
	dst_head = ft_create_node();
	current = dst_head;
	while (current)
	{
		current->value = head->value;
		if (head->next)
		{
			current->next = ft_create_node();
			if (!current->next)
				break ;
			current->next->prev = current;
		}
		current = current->next;
		head = head->next;
	}
	return (dst_head);
}

/* Frees both lists in utils. After reaching the
end of stack_a, will switch to head_b if it
exists. Uses the head_a pointer for freeing stack_b
aswell. Use only when program is finishing */

void	ft_free_lists(t_utils *utils)
{
	t_node	*temp;

	temp = NULL;
	while (utils->head_a)
	{
		temp = utils->head_a->next;
		free(utils->head_a);
		utils->head_a = NULL;
		utils->head_a = temp;
	}
	while (utils->head_b)
	{
		temp = utils->head_b->next;
		free(utils->head_b);
		utils->head_b = NULL;
		utils->head_b = temp;
	}
}

/* Gets the addresses of the tails of both stacks */
static void	ft_get_tails(t_utils *copy)
{
	t_node	*tail_a;
	t_node	*tail_b;

	tail_a = copy->head_a;
	tail_b = copy->head_b;
	while (tail_a && tail_a->next)
		tail_a = tail_a->next;
	while (tail_b && tail_b->next)
		tail_b = tail_b->next;
	copy->tail_a = tail_a;
	copy->tail_b = tail_b;
}

/* Copies the given dual linked lists to dst from
src. copy_list will break the copying if mallocfail occurs
and count_nodes will check that the node counts match */
void	ft_copy_utils(t_utils *dst, t_utils *src)
{
	dst->count_a = src->count_a;
	dst->count_b = src->count_b;
	dst->input_count = src->input_count;
	dst->sorted = src->sorted;
	dst->head_a = ft_copy_list(src->head_a);
	dst->head_b = ft_copy_list(src->head_b);
	if (count_nodes(dst->head_a) != dst->count_a || \
	count_nodes(dst->head_b) != dst->count_b)
	{
		ft_free_lists(dst);
		mallocfail(src);
	}
	ft_get_tails(dst);
}

size_t	count_nodes(t_node *head)
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
