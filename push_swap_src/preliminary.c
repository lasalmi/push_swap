/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preliminary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:59:22 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/02 15:53:47 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"


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

void push_rest_to_b(t_utils *utils, int i)
{
	
	while (contains_smaller(utils->head_a, utils->sorted[i]))
	{
		if (utils->head_a->value < utils->sorted[i])
			ft_pw_dispatcher(utils, 4);
		else
			ft_pw_dispatcher(utils, 5);
	}
	// while (utils->head_a)
	// 	ft_pw_dispatcher(utils, 4);
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

void	push_bigger_half_to_a(t_utils *utils, int pivot)
{
	t_node	*stack_b;

	stack_b = utils->head_b;
	while (contains_bigger(stack_b, pivot))
	{
		if (stack_b->value >= pivot)
			ft_pw_dispatcher(utils, 3);
		else
			ft_pw_dispatcher(utils, 6);
		stack_b = utils->head_b;
	}
}

void	sort_smaller_half(t_utils *utils, int pivot_index)
{
	int		than;

	than = utils->sorted[pivot_index];
	push_smaller_half_to_b(utils, than);
//	ft_printf("PUSHED SMALLER TO B\n");
//	ft_print_list(*utils);
	than = utils->sorted[pivot_index / 2];
	push_bigger_half_to_a(utils, than);
//	ft_print_list(*utils);
	than = utils->sorted[pivot_index / 4];
	push_bigger_half_to_a(utils, than);
//	ft_print_list(*utils);
	than = utils->sorted[pivot_index / 8];
	push_bigger_half_to_a(utils, than);
//	ft_print_list(*utils);
	than = utils->sorted[pivot_index];
//	ft_print_list(*utils);
	push_smaller_half_to_b(utils, than);
//	ft_printf("PUSHED BIGGER TO A\n");
//	ft_print_list(*utils);
	push_rest_to_b(utils, utils->sorted[pivot_index]);
	ft_print_list(*utils);
}

void	preliminary_stack_sort(t_utils *utils)
{
	int	pivot;
	int	i;
	int	chunk_size;
	
	chunk_size = utils->input_count / 2;
	i = (chunk_size - 1);
	pivot = utils->sorted[i];
	sort_smaller_half(utils, i);
	while (chunk_size > 1)
	{
		while (contains_smaller(utils->head_a, pivot))
		{
			if (utils->head_a->value < pivot)
				ft_pw_dispatcher(utils, 4);
			else
				ft_pw_dispatcher(utils, 5);
		}
//		ft_print_list(*utils);
		chunk_size /= 2;
		pivot = utils->sorted[utils->input_count - chunk_size];
	}
/*	sort_smaller_half(utils); */
//	ft_printf("PRELIMINARY DONE, PRINTING\n");
//	ft_print_list(*utils);
	push_rest_to_b(utils, utils->input_count - 1);
//	ft_print_list(*utils);
}