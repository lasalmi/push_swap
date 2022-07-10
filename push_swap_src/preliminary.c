/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preliminary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:59:22 by lasalmi           #+#    #+#             */
/*   Updated: 2022/07/10 13:49:37 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"
void push_rest_to_b(t_utils *utils)
{
	while (utils->count_a)
		ft_pw_dispatcher(utils, 4);
}

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

void preliminary_stack_sort(t_utils *utils)
{
	int	pivot;
	int	i;
	int	chunk_size;
	
	chunk_size = utils->input_count / 2;
	pivot = utils->sorted[utils->input_count - chunk_size];
	while (chunk_size >= 15)
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
//	ft_printlist(*utils);
	push_rest_to_b(utils);
//	ft_printlist(*utils);
}