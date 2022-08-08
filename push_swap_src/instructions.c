/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:25:21 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/08 16:58:48 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_type	is_combination(t_trgt a, t_trgt b, size_t cost)
{
	if (a.rev_cost + b.rotate_cost == cost)
		return (REVROT);
	if (a.rotate_cost + b.rev_cost == cost)
		return (ROTREV);
	return (NOT_FOUND);
}

t_type	same_direction(t_trgt a, t_trgt b, size_t cost)
{
	if (return_greater(a.rev_cost, b.rev_cost) == cost)
		return (REV);
	if (return_greater(a.rotate_cost, b.rotate_cost) == cost)
		return (ROTATE);
	return (NOT_FOUND);
}

void	generate_instructions(t_pair *pair)
{
	t_type	type;

	type = find_type(pair);
	if (type == ROTATE)
		gen_rotate(pair);
	else if (type == REV)
		gen_rev(pair);
	else if (type == REVROT)
		gen_revrot(pair);
	else if (type == ROTREV)
		gen_rotrev(pair);
}
