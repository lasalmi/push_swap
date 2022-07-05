/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:41:02 by lasalmi           #+#    #+#             */
/*   Updated: 2022/07/05 09:02:24 by lasalmi          ###   ########.fr       */
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
	while (utils->head_b)
	{
		ft_push_a(utils);
	}
}

/*void	ft_testchunks(t_utils *utils)
{
	t_solver	solverutils;

	ft_getchunks(utils, &solverutils);
	int i = 0;
	while (i < solverutils.chunk_amount)
	{
		ft_printf("Start: %d",solverutils.chunks[i].start);
		ft_printf("End: %d\n",solverutils.chunks[i++].end);
	}
} */

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
		ft_push_a(utils);
		cost++;
	}
	return (cost);
}

void	ft_preprocess(t_utils *utils)
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
			ft_push_b(utils);
			cost++;
			ft_printlist(*utils);
			free(pair.instructions);
			ft_printlist(*utils);
		}
	}
	free(solverutils.chunks);
	cost += ft_push_b_all(utils);
	ft_printlist(*utils);
	ft_printf("Cost: %llu", cost);
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
	ft_preprocess(&utils);
	free(utils.sorted);
	ft_freelists(&utils);
	return (0);
}
