/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:41:02 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/08 11:44:09 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Counts the cost of moving the value to the
bottom of the stack A. Returns negative,
if it is more efficient to use reverse rotate, returns 0
if already on top of stack A */
int	ft_count_trgt_a(int value_to_find, t_utils *utils)
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

size_t	ft_b_for_push(t_utils *utils)
{
	t_trgt		target;
	size_t		cost;

	cost = 0;
	target = ft_find_biggest(utils->head_b, utils->count_b);
	if (target.rev_cost < target.rotate_cost)
	{
		while (target.rev_cost)
		{
			ft_pw_dispatcher(utils, 9);
			cost++;
			target.rev_cost--;
		}
	}
	else
	{
		while (target.rotate_cost)
		{
			ft_pw_dispatcher(utils, 6);
			cost++;
			target.rotate_cost--;
		}
	}
	return (cost);
}

void	ft_process(t_utils *utils)
{
	if (ft_is_correct(utils))
		return ;
	ft_solver_large(utils);
}

int	main(int argc, char **argv)
{
	t_utils	utils;

	ft_initialize_utils(&utils);
	utils.caller = PUSH_SWAP;
	utils.head_b = NULL;
	if (argc < 2)
		return (0);
	ft_read_values(&utils, argv + 1, argc - 1);
	ft_sortvalues(&utils);
	ft_process(&utils);
	free(utils.sorted);
	ft_free_lists(&utils);
	return (0);
}
