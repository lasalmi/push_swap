/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:39:51 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/08 17:06:44 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_trgt	find_biggest(t_node *head, int stack_size)
{
	t_trgt	ret;
	int		biggest;
	int		i;

	i = 0;
	biggest = INT_MIN;
	initialize_target(&ret);
	if (!head)
		return (ret);
	while (head)
	{
		if (head->value > biggest)
		{
			ret = count_trgt(head->value, i, stack_size);
			biggest = ret.target;
		}
		head = head->next;
		i++;
	}
	return (ret);
}

t_trgt	find_smallest_pair(t_node *head, int stack_size)
{
	t_trgt	ret;
	int		smallest;
	int		i;

	i = 0;
	smallest = INT_MAX;
	initialize_target(&ret);
	if (!head)
		return (ret);
	while (head)
	{
		if (head->value < smallest)
		{
			ret = count_trgt(head->value, i, stack_size);
			smallest = ret.target;
		}
		head = head->next;
		i++;
	}
	return (ret);
}

/* Finds a pair in stack A for the value given as stack_b,
makes sure that stack_b is smaller and then counts the
diff with diff */
t_trgt	find_pair_for_b(int stack_b, t_node *head, int list_size)
{
	t_trgt	ret;
	int		i;
	int		diff;
	t_node	*temp;

	temp = head;
	i = 0;
	diff = INT_MAX;
	initialize_target(&ret);
	if (!head)
		return (ret);
	while (head)
	{
		if ((stack_b - head->value) < 0 && ft_diff(stack_b, head->value) < diff)
		{
			diff = ft_diff(stack_b, head->value);
			ret = count_trgt(head->value, i, list_size);
		}
		i++;
		head = head->next;
	}
	if (!ret.found)
		ret = find_smallest_pair(temp, list_size);
	return (ret);
}

/* Returns the smallest cost pair */
t_pair	find_pair(t_utils *utils)
{
	t_node	*head;
	t_pair	pair;
	int		i;

	i = 0;
	pair.total_cost = INT_MAX;
	head = utils->head_b;
	while (head)
	{
		if (total_cost_smaller(pair.total_cost, head->value, i, *utils))
		{
			pair.stack_b = count_trgt(head->value, i, utils->count_b);
			pair.stack_a = find_pair_for_b(head->value, \
			utils->head_a, utils->count_a);
			pair.total_cost = total_cost_move(pair.stack_a, pair.stack_b);
		}
		i++;
		head = head->next;
	}
	return (pair);
}

/* Finds the correct instruction combination
for getting A and B for the correct state for push */

t_type	find_type(t_pair *pair)
{
	t_type	ret;

	ret = same_direction(pair->stack_a, pair->stack_b, pair->total_cost);
	if (ret > NOT_FOUND)
		return (ret);
	ret = is_combination(pair->stack_a, pair->stack_b, pair->total_cost);
	if (ret > NOT_FOUND)
		return (ret);
	return (NOT_FOUND);
}
