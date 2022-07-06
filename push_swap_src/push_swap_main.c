/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:41:02 by lasalmi           #+#    #+#             */
/*   Updated: 2022/07/06 09:38:17 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

/* Loads the values from the original head_a
into an array of ints. All the integers need
to be in stack A */
void	ft_loadvalues(t_utils *utils)
{
	t_node	*list;
	int		*arr;

	arr = utils->sorted;
	list = utils->head_a;
	while (list)
	{
		*arr = list->value;
		list = list->next;
		arr++;
	}
}

/* Loads and sorts the values in the double linked list
into an array of integers */
void	ft_sortvalues(t_utils *utils)
{
	utils->sorted = (int *)malloc(sizeof(int) * utils->input_count);
	if (!utils->sorted)
		ft_error();
	ft_loadvalues(utils);
	ft_quicksortint(utils->sorted, utils->input_count);
}

/* Counts the cost of moving the value to the
bottom of the stack A. Returns negative,
if it is more efficient to use reverse rotate, returns 0
if already on top of stack A */
int	ft_countcost_a(int value_to_find, t_utils *utils)
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

int	ft_countcost_b(int value_to_find, t_utils *utils)
{
	int		i;
	int		j;
	t_node	*list;

	list = utils->head_b;
	i = 0;
	j = 0;
	if (!list)
		return (INT_MAX);
	while (list && value_to_find != list->value)
	{
		i++;
		list = list->next;
	}
	list = utils->tail_b;
	while (list && value_to_find != list->value)
	{
		j--;
		list = list->prev;
	}
	j--;
	if (ft_abs(j) > i)
		return (i);
	return (j);
}

void	ft_push_a_all(t_utils *utils)
{
	while (utils->head_b)
	{
		ft_pw_dispatcher(utils, 3);
	}
}

size_t	ft_b_for_push(t_utils *utils)
{
	t_cost	target;
	size_t	cost;

	cost = 0;
	target = ft_find_biggest(utils->head_b, utils->count_b);
	if (target.rev_cost > target.rotate_cost)
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

size_t	ft_push_b_all(t_utils *utils)
{
	size_t	cost;

	cost = 0;
	cost += ft_b_for_push(utils);
	while (utils->count_b)
	{
		ft_pw_dispatcher(utils, 3);
		cost++;
	}
	return (cost);
}

void	ft_process(t_utils *utils)
{
	if (ft_is_correct(utils))
		return ;
	else
		ft_solver_large(utils);
}

int	main(int argc, char **argv)
{
	t_utils	utils;

	ft_initutils(&utils);
	utils.caller = PUSH_SWAP;
	utils.head_b = NULL;
	if (argc < 2)
		ft_error();
	ft_read_values(&utils, argv + 1, argc - 1);
	ft_sortvalues(&utils);
	ft_process(&utils);
	free(utils.sorted);
	ft_freelists(&utils);
	return (0);
}
