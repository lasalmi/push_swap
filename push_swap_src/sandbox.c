/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:59:02 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/23 15:15:01 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	ft_cheapest_chunk(t_utils *original, t_solver *solver)
{
	int	i;
	int	lowest;
	int	cost;
	int	ret;

	ret = -1;
	lowest = INT_MAX;
	cost = 0;
	i = 0;
	while (i < solver->chunk_amount)
	{
		cost = ft_count_chunk_cost(original, solver, &solver->chunks[i]);
		if (cost < lowest)
			ret = i;
		i++;
	}
	return (ret);
}

void	ft_countnodes(t_utils *utils)
{
	t_node	*node;
	int		i;

	i = 0;
	node = utils->head_a;
	while (node)
	{
		i++;
		node = node->next;
	}
	ft_printf("Stack A: %d", i);
	i = 0;
	node = utils->head_b;
	while (node)
	{
		i++;
		node = node->next;
	}
	ft_printf("Stack B: %d\n", i);
}

/* Need to null solver "sorted", if used in sandbox */
int	ft_count_chunk_cost(t_utils	*original, t_solver *solver, t_chunk *chunk)
{
	t_utils		*sandbox;
	t_target	target;
	int			direction;
	int			cost;

	cost = 0;
	sandbox = ft_copystate(original);
	while (1)
	{
		target = ft_find_closest_a(chunk, sandbox->head_a, sandbox->tail_a);
/*		ft_printlist(*sandbox); */
		if (chunk->processed)
			break ;
/*		direction = ft_countcost_a(target, sandbox); */
		ft_get_target_costs(&target, sandbox);
		direction = target.rotate_cost;
		cost += (ft_abs(direction));
/*		if (direction < 0)
			ft_loop_dispatcher(abs(direction), sandbox, 8);
		if (direction > 0)
			ft_loop_dispatcher(direction, sandbox, 5); */
		ft_push_b(sandbox);
	}
	ft_printf("CHUNK LOW: %d CHUNK HIGH: %d\n", chunk->start, chunk->end);
	ft_printf("Cost of chunk: %i\n", cost);
	ft_printlist(*sandbox);
/*	ft_freelists(sandbox); */
	return (cost);
}
