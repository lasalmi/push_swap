/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:04:30 by lasalmi           #+#    #+#             */
/*   Updated: 2022/07/13 21:30:48 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"
static void rotate_a_to_finish(t_utils *utils)
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
		while (i--)
			ft_pw_dispatcher(utils, 5);
}
void	ft_solver_large(t_utils *utils)
{
	t_solver	solverutils;
	int			ret;
	t_pair		pair;
	size_t		cost;
	int			i;
//	int			j = 500; //
	i = 0;
	cost = 0;
	ft_getchunks(utils, &solverutils);
	preliminary_stack_sort(utils);
//	while (j--)//
//		ft_push_b(utils);//
//	ft_printlist(*utils); //
	ret = ft_cheapest_chunk(utils, &solverutils);
//	ft_printf("Exiting in solver large, cheapest chunk: %d\n", ret);//
	while (ret >= 0)
	{
		pair = ft_findpair(&solverutils.chunks[ret], utils);
//		ft_printf("SOLVER HAS PAIR: B: %d A: %d\n", pair.stack_b.target, pair.stack_a.target);
//		ft_printlist(*utils);
		if (pair.total_cost == INT_MAX)
		{
//			ft_printf("CHUNK HAS BEEN PUSHED TO A\n");
//			ft_printlist(*utils);
			solverutils.chunks[ret].sorted = 1;
			ret = ft_cheapest_chunk(utils, &solverutils);
//			ft_printf("Solver has new cheapest chunk: %d\n", ret);
		}
		if (pair.total_cost != INT_MAX)
		{
			ft_printf("PUSHING PAIR: A:%d B: %d\n", pair.stack_a.target, pair.stack_b.target);
			ft_printlist(*utils);
			ft_generate_instructions(&pair);
			cost += pair.total_cost;
			while (pair.total_cost--)
				ft_pw_dispatcher(utils, pair.instructions[i++]);
			i = 0;
			ft_pw_dispatcher(utils, 3);
			cost++;
			free(pair.instructions);
		}
	}
//	ft_printf("EXITING SOLVER:\n");
//	ft_printlist(*utils);
	rotate_a_to_finish(utils);
	free(solverutils.chunks);
//	cost += ft_push_b_all(utils);
}
