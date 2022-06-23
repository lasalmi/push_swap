/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:25:08 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/23 14:14:14 by lasalmi          ###   ########.fr       */
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
}

/* Calculates the total cost of moving piece from A to 
the right slot in stack B */

size_t	ft_total_cost_move(t_cost target_a, t_cost target_b)
{
	size_t	rotate_cost;
	size_t	rev_cost;

	rotate_cost = ft_returngreater(target_a.rotate_cost, target_b.rev_cost);
	rev_cost = ft_returngreater(target_a.rev_cost, target_b.rev_cost);
	if (rotate_cost < rev_cost)
		return (rotate_cost);
	return (rev_cost);
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
			ret = ft_count_cost(head->value, i, stack_size);
		head = head->next;
		i++;
	}
	return (ret);
}

/* Finds the nearest smaller number and if no smaller numbers are found
returns the biggest target in the stack */
t_cost	ft_find_pair(int stack_a, t_node *head, int list_size)
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
		ft_find_biggest(temp, list_size);
	return (ret);
}
