/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:55:59 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/02 13:19:12 by lasalmi          ###   ########.fr       */
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

/* Finds the smallest value in the given list */
int	ft_find_smallest(t_node *head)
{
	int smallest;

	smallest = INT_MAX;
	while (head)
	{
		if (head->value < smallest)
			smallest = head->value;
		head = head->next;
	}
	return (smallest);
}

int	need_to_swap(int head, int second, t_utils *utils)
{
	t_cost	largest;

	largest = ft_find_biggest(utils->head_a, utils->count_a);
	if (head > second && head != largest.target)
		return (1);
	if (head == largest.target && second != ft_find_smallest(utils->head_a))
		return (1);
	if (head == ft_find_smallest(utils->head_a) && second == largest.target)
		return (1);
	return (0);
}
/* Sorts stack A that has <= 3 integers. Swaps the integers
if needed when head value is NOT the largest value of the input 
TO DO: NEED TO MAKE THE SWAP IN A, IF HEAD is */
void	ft_sort_stack_a(t_utils *utils)
{
	int	head;
	int	second;
	int	rotate;
	while (!in_order(utils))
	{
		head = utils->head_a->value;
		second = utils->head_a->next->value;
		if (need_to_swap(head, second, utils))
			ft_pw_dispatcher(utils, 0);
		else
			ft_pw_dispatcher(utils, 5);
	}
//	ft_printf("STACK A IN ORDER:%d COUNT IN STACK: %d\n", in_order(utils), utils->count_a);
//	ft_print_list(*utils);
	rotate = ft_countcost_a(ft_find_smallest(utils->head_a), utils);
	if (rotate < 0)
	{

		rotate = ft_abs(rotate);
		while (rotate--)
			ft_pw_dispatcher(utils, 8);
	}
	else if (rotate > 0)
		while (rotate--)
			ft_pw_dispatcher(utils, 5);
}

void ft_sort_small(t_utils *utils)
{
	t_solver	solverutils;
	t_pair		pair;
	int			i;
	int			chunk;

	i = 0;
	ft_getchunks(utils, &solverutils);
	chunk = ft_cheapest_chunk(utils, &solverutils);
	while (1 && utils->count_a > 3)
	{
	pair = ft_findpair(&solverutils.chunks[chunk], utils);
	if (pair.total_cost == INT_MAX)
		break ;
	ft_generate_instructions(&pair);
	while(pair.total_cost--)
		ft_pw_dispatcher(utils, pair.instructions[i++]);
	i = 0;
	ft_pw_dispatcher(utils, 4);
	}
//	ft_printf("Sorting stack A");
//	ft_print_list(*utils);
	ft_sort_stack_a(utils);
	ft_push_b_all(utils);
	ft_sort_stack_a(utils);
}