/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:59:02 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/21 19:55:55 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

/* Need to null solver "sorted", if used in sandbox */
int	ft_count_chunk_cost(t_utils	*original, t_solver *solver, t_chunk *chunk)
{
	t_utils	*sandbox;
	int		target;
	int		direction;
	int		cost;

	cost = 0;
	sandbox = ft_copystate(original);
	while (1)
	{
		target = ft_find_closest_a(chunk, sandbox->head_a, sandbox->tail_a);
		ft_printf("Target: %d", target);
		ft_printlist(*sandbox);
		if (chunk->processed)
			break ;
		direction = ft_countcost(target, sandbox);
		cost += (ft_abs(direction));
		if (direction < 0)
			ft_loop_dispatcher(abs(direction), sandbox, 8);
		if (direction > 0)
			ft_loop_dispatcher(direction, sandbox, 5);
		ft_printlist(*sandbox);
		ft_push_b(sandbox);
		ft_printlist(*sandbox);
	}
//	ft_freelists(sandbox);
	return (cost);
}
