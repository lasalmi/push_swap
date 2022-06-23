/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:25:21 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/23 17:50:57 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

t_type	ft_iscombination(t_cost a, t_cost b, size_t cost)
{
	if (a.rev_cost + b.rotate_cost == cost)
		return (REVROT);
	if (a.rotate_cost + b.rev_cost == cost)
		return (ROTREV);
	return (NOT_FOUND);
}

t_type	ft_samedirection(t_cost a, t_cost b, size_t cost)
{
	if (ft_returngreater(a.rev_cost, b.rev_cost) == cost)
		return (REV);
	if (ft_returngreater(a.rotate_cost, b.rotate_cost) == cost)
		return (ROTATE);
	return (NOT_FOUND);
}

/* Finds the correct instruction combination
for getting A and B for the correct state for push */

t_type	ft_findtype(t_pair *pair)
{
	t_type	ret;

	ret = ft_samedirection(pair->stack_a, pair->stack_b, pair->total_cost);
	if (ret > NOT_FOUND)
		return (ret);
	ret = ft_iscombination(pair->stack_a, pair->stack_b, pair->total_cost);
	if (ret > NOT_FOUND)
		return (ret);
	return (NOT_FOUND);
}