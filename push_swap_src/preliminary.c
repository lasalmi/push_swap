/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preliminary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:59:22 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/08 11:37:27 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	contains_smaller(t_node *node, int pivot)
{
	while (node)
	{
		if (node->value < pivot)
			return (1);
		node = node->next;
	}
	return (0);
}

int	contains_bigger(t_node *node, int pivot)
{
	while (node)
	{
		if (node->value >= pivot)
			return (1);
		node = node->next;
	}
	return (0);
}

void	push_smaller_half_to_b(t_utils *utils, int pivot)
{
	t_node	*stack_a;

	stack_a = utils->head_a;
	while (contains_smaller(stack_a, pivot))
	{
		if (stack_a->value < pivot)
			ft_pw_dispatcher(utils, 4);
		else
			ft_pw_dispatcher(utils, 5);
		stack_a = utils->head_a;
	}
}

int	ft_small_stack(t_utils *utils)
{
	while (utils->count_a > 3)
		ft_pw_dispatcher(utils, 4);
	return (1);
}

void	preliminary_stack_sort(t_utils *utils)
{
	int		pivot;
	int		i;
	int		chunk_size;

	chunk_size = utils->input_count / 2;
	i = (chunk_size - 1);
	pivot = utils->sorted[i];
	if (utils->input_count <= 5 && ft_small_stack(utils))
		return ;
	while (chunk_size > 2)
	{
		while (contains_smaller(utils->head_a, pivot))
		{
			if (utils->head_a->value < pivot)
				ft_pw_dispatcher(utils, 4);
			else
				ft_pw_dispatcher(utils, 5);
		}
		chunk_size /= 2;
		pivot = utils->sorted[utils->input_count - chunk_size];
	}
	ft_sort_stack_a(utils);
}
