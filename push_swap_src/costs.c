/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:25:08 by lasalmi           #+#    #+#             */
/*   Updated: 2022/07/16 09:32:51 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

size_t	ft_returngreater(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}
/* Checks that the given value is a member of chunk */

int	ft_ismember(t_chunk *chunk, int value)
{
	return (value <= chunk->end && value >= chunk->start);
}

/* Calculates the cost of the given member in index i in the list*/
t_cost	ft_count_cost(int member, int i, int stack_size)
{
	t_cost	ret;

	ret.found = 1;
	ret.target = member;
	ret.rotate_cost = i;
	ret.rev_cost = stack_size - i;
	return (ret);
}

size_t	ft_returnsmallest(size_t a, size_t b, size_t c, size_t d)
{
	if (a <= b && a <= c && a <= d)
		return (a);
	if (b <= a && b <= c && b <= d)
		return (b);
	if (c <= a && c <= b && c <= d)
		return (c);
	return (d);
}

/* Calculates the total cost of moving piece from A to 
the right slot in stack B. Rotrev and revrot are
movements without rotating the stacks in the same direction */

size_t	ft_total_cost_move(t_cost target_a, t_cost target_b)
{
	size_t	rotate_cost;
	size_t	rev_cost;
	size_t	rotrev;
	size_t	revrot;

	rotrev = target_a.rotate_cost + target_b.rev_cost;
	revrot = target_a.rev_cost + target_b.rev_cost;
	rotate_cost = ft_returngreater(target_a.rotate_cost, target_b.rotate_cost);
	rev_cost = ft_returngreater(target_a.rev_cost, target_b.rev_cost);
	return (ft_returnsmallest(rotate_cost, rev_cost, rotrev, revrot));
}

void	ft_initialize_target(t_cost	*cost)
{
	cost->target = 0;
	cost->rev_cost = 0;
	cost->rotate_cost = 0;
	cost->found = 0;
}

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
//			ft_printf("IF IN FIND PAIR FOR B: %d, FOUND: %d\n", stack_b, head->value);
			diff = ft_diff(stack_b, head->value);
	//		ft_printf("DIFF IS: %d", diff);
			ret = ft_count_cost(head->value, i, list_size);
		}
		i++;
		head = head->next;
	}
	if (!ret.found)
		ret = ft_find_smallest_pair(temp, list_size);
	return (ret);
}

int	ft_total_cost_smaller(int total_cost, int b_value, int i, t_utils utils)
{
	t_pair	to_compare;

//	ft_printf("In total cost smaller, total cost: %d B-value: %d, index: %d\n", total_cost, b_value, i);
	to_compare.stack_b = ft_count_cost(b_value, i, utils.count_b);
	to_compare.stack_a = ft_find_pair_for_b(b_value, utils.head_a, \
	utils.count_a);
	to_compare.total_cost = ft_total_cost_move(to_compare.stack_a, \
	to_compare.stack_b);
	if (to_compare.total_cost < total_cost)
		return (1);
	return (0);
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
//		ft_printf("TRAVERSING THROUGH B, VALUE: %d CHUNK START: %d CHUNK END: %d\n", head->value, chunk->start, chunk->end);
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
