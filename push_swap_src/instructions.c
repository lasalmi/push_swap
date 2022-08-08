/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:25:21 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/08 13:59:12 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_type	ft_iscombination(t_trgt a, t_trgt b, size_t cost)
{
	if (a.rev_cost + b.rotate_cost == cost)
		return (REVROT);
	if (a.rotate_cost + b.rev_cost == cost)
		return (ROTREV);
	return (NOT_FOUND);
}

t_type	ft_samedirection(t_trgt a, t_trgt b, size_t cost)
{
	if (ft_returngreater(a.rev_cost, b.rev_cost) == cost)
		return (REV);
	if (ft_returngreater(a.rotate_cost, b.rotate_cost) == cost)
		return (ROTATE);
	return (NOT_FOUND);
}

void	ft_generate_instructions(t_pair *pair)
{
	t_type	type;

	type = ft_findtype(pair);
	if (type == ROTATE)
		ft_gen_rotate(pair);
	else if (type == REV)
		ft_gen_rev(pair);
	else if (type == REVROT)
		ft_gen_revrot(pair);
	else if (type == ROTREV)
		ft_gen_rotrev(pair);
}
