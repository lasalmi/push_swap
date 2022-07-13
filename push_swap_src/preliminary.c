/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preliminary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:59:22 by lasalmi           #+#    #+#             */
/*   Updated: 2022/07/13 21:15:38 by lasalmi          ###   ########.fr       */
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

void	sort_smaller_half(t_utils *utils)
{
	int	pivot;
	size_t	i;
	size_t	chunk_size;

	chunk_size = utils->input_count / 2;
	i = utils->input_count - chunk_size;
	pivot = utils->sorted[i];

	while (chunk_size >= 15 && i >= 15)
	{
		while (contains_smaller(utils->head_a, pivot))
		{
			if (utils->head_a->value < pivot)
				ft_pw_dispatcher(utils, 4);
			else
				ft_pw_dispatcher(utils, 5);
		}
//		ft_printf("FIRST LOOP\n");
//		ft_printlist(*utils);
		chunk_size /= 2;
		i /= 2;
		pivot = utils->sorted[i];
//		ft_printf("PIVOT: %d", pivot);
		while (contains_bigger(utils->head_b, pivot) && chunk_size >= 30)
		{
//			ft_printf("HEAD B VALUE: %d\n", utils->head_b->value);
			if (utils->head_b->value >= pivot)
				ft_pw_dispatcher(utils, 3);
			else
				ft_pw_dispatcher(utils, 9);
		}
		chunk_size /= 2;
		i /= 2;
		pivot = utils->sorted[i];
	}
	ft_printf("FIRST HALF DONE\n");
	ft_printlist(*utils);
	push_rest_to_b(utils);
}

void	preliminary_stack_sort(t_utils *utils)
{
	int	pivot;
	int	i;
	int	chunk_size;
	
	chunk_size = utils->input_count / 2;
	i = (chunk_size - 1) / 2;
	pivot = utils->sorted[i];
	while (chunk_size > 1)
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
/*	sort_smaller_half(utils); */
// ft_printlist(*utils);
//	push_rest_to_b(utils);
//	ft_printlist(*utils);
}