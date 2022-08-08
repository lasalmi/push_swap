/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:55:59 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/08 16:52:14 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*Finds the smallest value in the given list */
int	find_smallest(t_node *head)
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

int	need_to_ft_swap(int head, int second, t_utils *utils)
{
	t_trgt	largest;

	largest = find_biggest(utils->head_a, utils->count_a);
	if (head > second && head != largest.target)
		return (1);
	if (head == largest.target && second != find_smallest(utils->head_a))
		return (1);
	if (head == find_smallest(utils->head_a) && second == largest.target)
		return (1);
	return (0);
}

/* Sorts stack A that has <= 3 integers. ft_swaps the integers
if needed when head value is NOT the largest value of the input 
TO DO: NEED TO MAKE THE ft_swap IN A, IF HEAD is */
void	sort_stack_a(t_utils *utils)
{
	int	head;
	int	second;
	int	rotate;

	while (!in_order(utils))
	{
		head = utils->head_a->value;
		second = utils->head_a->next->value;
		if (need_to_ft_swap(head, second, utils))
			pw_dispatcher(utils, 0);
		else
			pw_dispatcher(utils, 5);
	}
	rotate = count_trgt_a(find_smallest(utils->head_a), utils);
	if (rotate < 0)
	{
		rotate = abs(rotate);
		while (rotate--)
			pw_dispatcher(utils, 8);
	}
	else if (rotate > 0)
		while (rotate--)
			pw_dispatcher(utils, 5);
}
