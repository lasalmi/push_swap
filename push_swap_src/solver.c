/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:04:30 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/07 13:30:26 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static void	rotate_a_to_finish(t_utils *utils)
{
	int	movement;
	int	i;

	i = 0;
	movement = ft_countcost_a(utils->sorted[0], utils);
	if (movement < 0)
	{
		i = ft_abs(movement);
		while (i--)
			ft_pw_dispatcher(utils, 8);
	}
	else
	{
		i = movement;
		while (i--)
			ft_pw_dispatcher(utils, 5);
	}
}

void	move_pair(t_utils *utils, t_pair *pair, size_t *cost)
{
	size_t	i;

	i = 0;
	ft_generate_instructions(pair);
	*cost += pair->total_cost;
	while (pair->total_cost--)
		ft_pw_dispatcher(utils, pair->instructions[i++]);
	ft_pw_dispatcher(utils, 3);
	(*cost)++;
	free(pair->instructions);
}

void	ft_solver_large(t_utils *utils)
{
	t_solver	solverutils;
	int			ret;
	t_pair		pair;
	size_t		cost;

	cost = 0;
	ft_getchunks(utils, &solverutils);
	preliminary_stack_sort(utils);
	ft_sort_stack_a(utils);
	ret = ft_cheapest_chunk(utils, &solverutils);
	while (ret >= 0)
	{
		pair = ft_findpair(&solverutils.chunks[ret], utils);
		if (pair.total_cost == INT_MAX)
		{
			solverutils.chunks[ret].sorted = 1;
			ret = ft_cheapest_chunk(utils, &solverutils);
		}
		if (pair.total_cost != INT_MAX)
			move_pair(utils, &pair, &cost);
	}
	rotate_a_to_finish(utils);
	free(solverutils.chunks);
}
