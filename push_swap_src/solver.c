/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:04:30 by lasalmi           #+#    #+#             */
/*   Updated: 2022/07/07 10:40:39 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ft_solver_large(t_utils *utils)
{
	t_solver	solverutils;
	int			ret;
	t_pair		pair;
	size_t		cost;
	int			i;

	i = 0;
	cost = 0;
	ft_getchunks(utils, &solverutils);
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
		{
			ft_generate_instructions(&pair);
			cost += pair.total_cost;
			while (pair.total_cost--)
				ft_pw_dispatcher(utils, pair.instructions[i++]);
			i = 0;
			ft_pw_dispatcher(utils, 4);
			cost++;
			free(pair.instructions);
		}
	}
	free(solverutils.chunks);
	cost += ft_push_b_all(utils);
}
