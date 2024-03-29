/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:25:08 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/08 16:58:28 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	return_greater(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

/* Calculates the cost of the given member in index i in the list*/
t_trgt	count_trgt(int member, int i, int stack_size)
{
	t_trgt	ret;

	ret.found = 1;
	ret.target = member;
	ret.rotate_cost = i;
	ret.rev_cost = stack_size - i;
	return (ret);
}

size_t	return_smallest(size_t a, size_t b, size_t c, size_t d)
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

size_t	total_cost_move(t_trgt target_a, t_trgt target_b)
{
	size_t	rotate_cost;
	size_t	rev_cost;
	size_t	rotrev;
	size_t	revrot;

	rotrev = target_a.rotate_cost + target_b.rev_cost;
	revrot = target_a.rev_cost + target_b.rev_cost;
	rotate_cost = return_greater(target_a.rotate_cost, target_b.rotate_cost);
	rev_cost = return_greater(target_a.rev_cost, target_b.rev_cost);
	return (return_smallest(rotate_cost, rev_cost, rotrev, revrot));
}

int	total_cost_smaller(size_t total_cost, int b_value, int i, t_utils utils)
{
	t_pair	to_compare;

	to_compare.stack_b = count_trgt(b_value, i, utils.count_b);
	to_compare.stack_a = find_pair_for_b(b_value, utils.head_a, \
	utils.count_a);
	to_compare.total_cost = total_cost_move(to_compare.stack_a, \
	to_compare.stack_b);
	if (to_compare.total_cost < total_cost)
		return (1);
	return (0);
}
