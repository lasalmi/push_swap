/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:55:59 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/07 15:39:44 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

/*Finds the smallest value in the given list */
int	ft_find_smallest(t_node *head)
{
	int	smallest;

	smallest = INT_MAX;
	while (head)
	{
		if (head->value < smallest)
			smallest = head->value;
		head = head->next;
	}
	return (smallest);
}

int	need_to_swap(int head, int second, t_utils *utils)
{
	t_trgt	largest;

	largest = ft_find_biggest(utils->head_a, utils->count_a);
	if (head > second && head != largest.target)
		return (1);
	if (head == largest.target && second != ft_find_smallest(utils->head_a))
		return (1);
	if (head == ft_find_smallest(utils->head_a) && second == largest.target)
		return (1);
	return (0);
}

/* Sorts stack A that has <= 3 integers. Swaps the integers
if needed when head value is NOT the largest value of the input 
TO DO: NEED TO MAKE THE SWAP IN A, IF HEAD is */
void	ft_sort_stack_a(t_utils *utils)
{
	int	head;
	int	second;
	int	rotate;

	while (!in_order(utils))
	{
		head = utils->head_a->value;
		second = utils->head_a->next->value;
		if (need_to_swap(head, second, utils))
			ft_pw_dispatcher(utils, 0);
		else
			ft_pw_dispatcher(utils, 5);
	}
	rotate = ft_count_trgt_a(ft_find_smallest(utils->head_a), utils);
	if (rotate < 0)
	{
		rotate = ft_abs(rotate);
		while (rotate--)
			ft_pw_dispatcher(utils, 8);
	}
	else if (rotate > 0)
		while (rotate--)
			ft_pw_dispatcher(utils, 5);
}
