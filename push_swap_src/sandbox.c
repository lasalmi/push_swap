/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:59:02 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/23 19:51:04 by lasalmi          ###   ########.fr       */
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
		{
			ret = i;
			lowest = cost;
		}
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
	t_pair		pair;
	int			cost;
	int			i;

	i = 0;
	cost = 0;
	sandbox = ft_copystate(original);
	while (1)
	{
		pair = ft_findpair(chunk, sandbox);
		if (pair.total_cost == INT_MAX)
			break ;
//		ft_printf("Pair:%d %d Cost: %d\n", pair.stack_a.target, pair.stack_b.target, pair.total_cost);
		ft_generate_instructions(&pair);
		cost += pair.total_cost;
		while (pair.total_cost--)
			ft_pw_dispatcher(sandbox, pair.instructions[i++]);
		i = 0;
		ft_push_b(sandbox);
		free(pair.instructions);
		ft_printlist(*sandbox);
	}
	ft_printf("Type of instruction: %d\n", ft_findtype(&pair));
	ft_printf("CHUNK LOW: %d CHUNK HIGH: %d\n", chunk->start, chunk->end);
	ft_printf("Cost of chunk: %i\n", cost);
//	ft_printlist(*sandbox);

	ft_push_b(sandbox);
//	ft_printlist(*sandbox);
/*	ft_freelists(sandbox); */
	return (cost);
}
