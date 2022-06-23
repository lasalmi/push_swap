/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:25:08 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/23 12:49:25 by lasalmi          ###   ########.fr       */
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