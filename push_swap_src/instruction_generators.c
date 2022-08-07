/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_generators.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:36:22 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/07 15:03:19 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

/* Generates rotate instructions for rotate pair */
void	ft_gen_rotate(t_pair *pair)
{
	int		rr;
	int		ra;
	int		rb;
	size_t	i;

	i = 0;
	pair->instructions = (int *)malloc(sizeof(int) * pair->total_cost);
	if (!pair->instructions)
		ft_error();
	ra = 0;
	rb = 0;
	if (pair->stack_a.rotate_cost < pair->stack_b.rotate_cost)
		rr = pair->stack_a.rotate_cost;
	else
		rr = pair->stack_b.rotate_cost;
	if (pair->stack_a.rotate_cost < pair->stack_b.rotate_cost)
		rb = pair->stack_b.rotate_cost - rr;
	else
		ra = pair->stack_a.rotate_cost - rr;
	while (rr--)
		pair->instructions[i++] = 7;
	while (ra--)
		pair->instructions[i++] = 5;
	while (rb--)
		pair->instructions[i++] = 6;
}

/* Generates revrot instructions for revrot pair */
void	ft_gen_rev(t_pair *pair)
{
	int		rrr;
	int		rra;
	int		rrb;
	size_t	i;

	i = 0;
	pair->instructions = (int *)malloc(sizeof(int) * pair->total_cost);
	if (!pair->instructions)
		ft_error();
	rra = 0;
	rrb = 0;
	if (pair->stack_a.rev_cost < pair->stack_b.rev_cost)
		rrr = pair->stack_a.rev_cost;
	else
		rrr = pair->stack_b.rev_cost;
	if (pair->stack_a.rev_cost < pair->stack_b.rev_cost)
		rrb = pair->stack_b.rev_cost - rrr;
	else
		rra = pair->stack_a.rev_cost - rrr;
	while (rrr--)
		pair->instructions[i++] = 10;
	while (rra--)
		pair->instructions[i++] = 8;
	while (rrb--)
		pair->instructions[i++] = 9;
}

void	ft_gen_rotrev(t_pair *pair)
{
	int	ra;
	int	rrb;
	int	i;

	i = 0;
	pair->instructions = (int *)malloc(sizeof(int) * pair->total_cost);
	if (!pair->instructions)
		ft_error();
	ra = pair->stack_a.rotate_cost;
	rrb = pair->stack_b.rev_cost;
	while (ra--)
		pair->instructions[i++] = 5;
	while (rrb--)
		pair->instructions[i++] = 9;
}

void	ft_gen_revrot(t_pair *pair)
{
	int	rra;
	int	rb;
	int	i;

	i = 0;
	pair->instructions = (int *)malloc(sizeof(int) * pair->total_cost);
	if (!pair->instructions)
		ft_error();
	rra = pair->stack_a.rev_cost;
	rb = pair->stack_b.rotate_cost;
	while (rra--)
		pair->instructions[i++] = 8;
	while (rb--)
		pair->instructions[i++] = 6;
}

int	ft_count_cost_b(int value_to_find, t_utils *utils)
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
