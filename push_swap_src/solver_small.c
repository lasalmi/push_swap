/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:55:59 by lasalmi           #+#    #+#             */
/*   Updated: 2022/07/09 10:26:23 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static	int	ft_are_consecutive(t_utils *utils, int a, int b)
{
	size_t	i;
//	uint8_t	consecutive;

//	consecutive = 0;
	i = 0;
	while (i < utils->input_count && utils->sorted[i] != a)
		i++;
	if (i > 0 && i < (utils->input_count - 1))
		return (b == utils->sorted[i - 1] || b == utils->sorted[i + 1]);
	if (i == (utils->input_count - 1) && i > 0)
		return (b == utils->sorted[i - 1] && b == utils->sorted[0]);
	if (i == 0)
		return (b == utils->sorted[i + 1] || b == utils->sorted[utils->input_count - 1]);
	return (0);
}

void ft_sort_small(t_utils *utils)
{
	t_solver	solverutils;
	t_pair		pair;
	int			i;

	i = 0;
	ft_getchunks(utils, &solverutils);
	while (1)
	{
	pair = ft_findpair(&solverutils.chunks[0], utils);
	if (pair.total_cost == INT_MAX)
		break ;
	ft_generate_instructions(&pair);
	while(pair.total_cost--)
		ft_pw_dispatcher(utils, pair.instructions[i++]);
	i = 0;
	ft_pw_dispatcher(utils, 4);
//	ft_printlist(*utils);
	}
	if (utils->head_a->next && utils->head_a->value > utils->head_a->next->value)
		ft_pw_dispatcher(utils, 0);
	ft_push_b_all(utils);
//	ft_printlist(*utils);
}