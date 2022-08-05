/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:59:02 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/05 19:22:36 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"
/* Traverses through all the chunks that are not yet
sorted (aka, tested) and counts the cost of the chunk,
and returns the index of the cheapest chunk */
int	ft_cheapest_chunk(t_utils *original, t_solver *solver)
{
	size_t	i;
	int		lowest;
	int		cost;
	int		ret;

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
		cost = ft_count_chunk_cost(original, &solver->chunks[i]);
		if (cost < lowest)
		{
			ret = i;
			lowest = cost;
		}
		i++;
	}
	return (ret);
}

void	ft_count_nodes(t_utils *utils)
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
int	ft_count_chunk_cost(t_utils	*original, t_chunk *chunk)
{
	t_utils		sandbox;
	t_pair		pair;
	int			cost;
	size_t		i;

	i = 0;
	cost = 0;
	ft_copy_utils(&sandbox, original);
	sandbox.caller = SANDBOX;
	while (1)
	{
		pair = ft_findpair(chunk, &sandbox);
		if (pair.total_cost == INT_MAX)
			break ;
		ft_generate_instructions(&pair);
		cost += pair.total_cost;
		while (pair.total_cost--)
			ft_pw_dispatcher(&sandbox, pair.instructions[i++]);
		i = 0;
		ft_push_a(&sandbox);
		free(pair.instructions);
	}
	ft_push_b(&sandbox);
	ft_free_lists(&sandbox);
	return (cost);
}
