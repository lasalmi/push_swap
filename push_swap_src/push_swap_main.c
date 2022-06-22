/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:41:02 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/23 00:21:05 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

/* Loads the values from the original head_a
into an array of ints. All the integers need
to be in stack A */
void ft_loadvalues(t_utils *utils)
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

void	ft_loop_dispatcher(size_t n, t_utils *utils, int instruction)
{
	utils->instr_count += n;
	while(n--)
		ft_pw_dispatcher(utils, instruction);
}

/* Counts the cost of moving the value to the
bottom of the stack A. Returns negative,
if it is more efficient to use reverse rotate, returns 0
if already in bottom of stack A */
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
	while(utils->head_b)
	{
		ft_push_a(utils);
	}
}
/*
void	ft_solve(t_utils *utils, int *sorted)
{
	size_t	current;
	t_node	*stack_a;
	int		cost;

	stack_a = utils->head_a;
	current = 0;
	while (utils->head_a->next)
	{
		cost = ft_countcost(sorted[current], utils);
		ft_printf("Cost: %d\n", cost);
		ft_printlist(*utils);
		if (cost < 0)
			ft_loop_dispatcher(abs(cost), utils, 8);
		if (cost > 0)
			ft_loop_dispatcher(cost, utils, 5);
		ft_push_b(utils);
		utils->instr_count++;
		current++;
		stack_a = utils->head_a;
	}
	ft_printlist(*utils);
	ft_push_a_all(utils);
} */

void	ft_testchunks(t_utils *utils)
{
	t_solver	solverutils;

	ft_getchunks(utils, &solverutils);
	int i = 0;
	while (i < solverutils.chunk_amount)
	{
		ft_printf("Start: %d",solverutils.chunks[i].start);
		ft_printf("End: %d\n",solverutils.chunks[i++].end);
	}
}

void	ft_preprocess(t_utils *utils)
{
	t_solver	solverutils;

	ft_getchunks(utils, &solverutils);
	ft_printf("CHEAPEST CHUNK INDEX: %d\n", ft_cheapest_chunk(utils, &solverutils));
//	ft_printf("Cost: %d", ft_count_chunk_cost(utils, &solverutils, &solverutils.chunks[0]));
}

int	main(int argc, char **argv)
{
	t_utils	utils;

	ft_initutils(&utils);
	utils.head_b = NULL;
	if (argc < 2)
		ft_error();
	ft_read_values(&utils, argv + 1, argc - 1);
	ft_sortvalues(&utils);
//	ft_printlist(utils);
//	ft_solve(&utils, utils.sorted);
	ft_preprocess(&utils);
//	ft_printlist(utils);
//	ft_printf("%llu", utils.instr_count);
	ft_freelists(&utils);
	return (0);
}
