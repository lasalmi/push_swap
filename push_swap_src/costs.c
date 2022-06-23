/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:25:08 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/23 17:00:21 by lasalmi          ###   ########.fr       */
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

int	ft_ismember(t_chunk *chunk, int	value)
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
	if (a < b && a < c && a < d)
		return (a);
	if (b < a && b < c && b < d)
		return (b);
	if (c < a && c < b && c < d)
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
	ft_printf("A: Rev:%llu Rot:%llu\n", target_a.rev_cost, target_a.rotate_cost);
	ft_printf("B: Rev:%llu Rot:%llu\n", target_b.rev_cost, target_b.rotate_cost);
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
	biggest = 0;
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

/* Finds the nearest smaller number and if no smaller numbers are found
returns the biggest target in the stack B */
t_cost	ft_find_pair_for_a(int stack_a, t_node *head, int list_size)
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
		if ((stack_a - head->value) > 0 && (stack_a - head->value) < diff)
		{
			diff = stack_a - head->value;
			ret = ft_count_cost(head->value, i, list_size);
		}
		i++;
		head = head->next;
	}
	if (!ret.found)
		ret = ft_find_biggest(temp, list_size);
	return (ret);
}

int	ft_total_cost_smaller(int total_cost, int a_value, int i, t_utils utils)
{
	t_pair	to_compare;

	to_compare.stack_a = ft_count_cost(a_value, i, utils.count_a);
	to_compare.stack_b = ft_find_pair_for_a(a_value, utils.head_b, utils.count_b);
	to_compare.total_cost = ft_total_cost_move(to_compare.stack_a, to_compare.stack_b);
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
	head = utils->head_a;
	while (head)
	{
		if (ft_ismember(chunk, head->value) && ft_total_cost_smaller(pair.total_cost, head->value, i, *utils))
		{
			pair.stack_a = ft_count_cost(head->value, i, utils->count_a);
			pair.stack_b = ft_find_pair_for_a(head->value, utils->head_b, utils->count_b);
			pair.total_cost = ft_total_cost_move(pair.stack_a, pair.stack_b);
			ft_printf("Findpair: A:%d B:%d Total%llu\n", pair.stack_a.target, pair.stack_b.target, pair.total_cost);
		}
		i++;
		head = head->next;
	}
	return (pair);
}
