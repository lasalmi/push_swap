/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:59:02 by lasalmi           #+#    #+#             */
/*   Updated: 2022/07/10 12:46:56 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"
/* Traverses through all the chunks that are not yet
sorted (aka, tested) and counts the cost of the chunk,
and returns the index of the cheapest chunk */
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
		while (solver->chunks[i].sorted)
			i++;
		if (i >= solver->chunk_amount)
			break ;
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
	i = 0;
	node = utils->head_b;
	while (node)
	{
		i++;
		node = node->next;
	}
}

/* Copies the state of the current problem as a sandbox,
sets the caller so that the instructions dont get printed out. Finds the cheapest
pair at each loop of the while and when there are no more members of the chunk
in stack A it breaks the loop and returns the total cost of that chunk */
int	ft_count_chunk_cost(t_utils	*original, t_solver *solver, t_chunk *chunk)
{
	t_utils		*sandbox;
	t_pair		pair;
	int			cost;
	int			i;

	i = 0;
	cost = 0;
	sandbox = ft_copystate(original);
	sandbox->caller = SANDBOX;
	while (1)
	{
		pair = ft_findpair(chunk, sandbox);
//	ft_printf("Pair found pair.a: %d pair.b: %d Total cost: %llu \n", pair.stack_a.target, pair.stack_b.target, pair.total_cost);
		if (pair.total_cost == INT_MAX)
			break ;
		ft_generate_instructions(&pair);
		cost += pair.total_cost;
		while (pair.total_cost--)
			ft_pw_dispatcher(sandbox, pair.instructions[i++]);
		i = 0;
		ft_push_a(sandbox);
//		ft_printf("PUSHED A\n");
//		ft_printlist(*sandbox);
		free(pair.instructions);
	}
	ft_push_b(sandbox);
	ft_freelists(sandbox);
	free(sandbox);
	return (cost);
}
