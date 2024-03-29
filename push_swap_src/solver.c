/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:04:30 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/08 19:13:43 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_a_to_finish(t_utils *utils)
{
	int	movement;
	int	i;

	i = 0;
	movement = count_trgt_a(utils->sorted[0], utils);
	if (movement < 0)
	{
		i = ft_abs(movement);
		while (i--)
			pw_dispatcher(utils, 8);
	}
	else
	{
		i = movement;
		while (i--)
			pw_dispatcher(utils, 5);
	}
}

void	move_pair(t_utils *utils, t_pair *pair)
{
	size_t	i;

	i = 0;
	generate_instructions(pair);
	if (!pair->instructions)
	{
		free(utils->sorted);
		free_stacks(utils);
		exit(2);
	}
	while (pair->total_cost--)
		pw_dispatcher(utils, pair->instructions[i++]);
	pw_dispatcher(utils, 3);
	free(pair->instructions);
}

void	solver_large(t_utils *utils)
{
	int			sorted;
	t_pair		pair;

	preliminary_stack_sort(utils);
	sort_stack_a(utils);
	sorted = 0;
	while (!sorted)
	{
		pair = find_pair(utils);
		if (pair.total_cost == INT_MAX)
			sorted = 1;
		if (pair.total_cost != INT_MAX)
			move_pair(utils, &pair);
	}
	rotate_a_to_finish(utils);
}
