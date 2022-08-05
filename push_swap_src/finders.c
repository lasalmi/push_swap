/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:39:51 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/05 13:57:59 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"

t_cost	ft_find_biggest(t_node *head, int stack_size)
{
	t_cost	ret;
	int		biggest;
	int		i;

	i = 0;
	biggest = INT_MIN;
	ft_initialize_target(&ret);
	if (!head)
		return (ret);
	while (head)
	{
		if (head->value > biggest)
		{
			ret = ft_count_cost(head->value, i, stack_size);
			biggest = ret.target;
		}
		head = head->next;
		i++;
	}
	return (ret);
}

t_cost	ft_find_smallest_pair(t_node *head, int stack_size)
{
	t_cost	ret;
	int		smallest;
	int		i;

	i = 0;
	smallest = INT_MAX;
	ft_initialize_target(&ret);
	if (!head)
		return (ret);
	while (head)
	{
		if (head->value < smallest)
		{
			ret = ft_count_cost(head->value, i, stack_size);
			smallest = ret.target;
		}
		head = head->next;
		i++;
	}
	return (ret);
}

/* Finds a pair in stack A for the value given as stack_b,
makes sure that stack_b is smaller and then counts the
diff with ft_diff */
t_cost	ft_find_pair_for_b(int stack_b, t_node *head, int list_size)
{
	t_cost	ret;
	int		i;
	int		diff;
	t_node	*temp;

	temp = head;
	i = 0;
	diff = INT_MAX;
	ft_initialize_target(&ret);
	if (!head)
		return (ret);
	while (head)
	{
		if ((stack_b - head->value) < 0 && ft_diff(stack_b, head->value) < diff)
		{
			diff = ft_diff(stack_b, head->value);
			ret = ft_count_cost(head->value, i, list_size);
		}
		i++;
		head = head->next;
	}
	if (!ret.found)
		ret = ft_find_smallest_pair(temp, list_size);
	return (ret);
}

/* Returns the smallest cost pair within given chunk */
t_pair	ft_findpair(t_chunk *chunk, t_utils *utils)
{
	t_node	*head;
	t_pair	pair;
	int		i;

	i = 0;
	pair.total_cost = INT_MAX;
	head = utils->head_b;
	while (head)
	{
		if (ft_ismember(chunk, head->value) && \
		ft_total_cost_smaller(pair.total_cost, head->value, i, *utils))
		{
			pair.stack_b = ft_count_cost(head->value, i, utils->count_b);
			pair.stack_a = ft_find_pair_for_b(head->value, \
			utils->head_a, utils->count_a);
			pair.total_cost = ft_total_cost_move(pair.stack_a, pair.stack_b);
		}
		i++;
		head = head->next;
	}
	return (pair);
}
