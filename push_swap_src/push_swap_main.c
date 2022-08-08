/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:41:02 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/08 19:14:17 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Counts the cost of moving the value to the
top of the stack A. Returns negative,
if it is more efficient to use reverse rotate, returns 0
if already on top of stack A */
int	count_trgt_a(int value_to_find, t_utils *utils)
{
	int		i;
	int		j;
	t_node	*list;

	list = utils->head_a;
	i = 0;
	j = 0;
	if (!list)
		return (0);
	while (value_to_find != list->value)
	{
		i++;
		list = list->next;
	}
	list = utils->tail_a;
	while (value_to_find != list->value)
	{
		j--;
		list = list->prev;
	}
	j--;
	if (ft_abs(j) > i)
		return (i);
	return (j);
}

size_t	b_for_push(t_utils *utils)
{
	t_trgt		target;
	size_t		cost;

	cost = 0;
	target = find_biggest(utils->head_b, utils->count_b);
	if (target.rev_cost < target.rotate_cost)
	{
		while (target.rev_cost)
		{
			pw_dispatcher(utils, 9);
			cost++;
			target.rev_cost--;
		}
	}
	else
	{
		while (target.rotate_cost)
		{
			pw_dispatcher(utils, 6);
			cost++;
			target.rotate_cost--;
		}
	}
	return (cost);
}

void	process(t_utils *utils)
{
	if (is_correct(utils))
		return ;
	solver_large(utils);
}

int	main(int argc, char **argv)
{
	t_utils	utils;

	initialize_utils(&utils);
	utils.caller = PUSH_ft_swap;
	utils.head_b = NULL;
	if (argc < 2)
		return (0);
	read_values(&utils, argv + 1, argc - 1);
	sort_values(&utils);
	process(&utils);
	free(utils.sorted);
	free_stacks(&utils);
	return (0);
}
