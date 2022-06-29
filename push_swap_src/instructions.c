/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:25:21 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/29 14:14:58 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

t_type	ft_iscombination(t_cost a, t_cost b, size_t cost)
{
	if (a.rev_cost + b.rotate_cost == cost)
		return (REVROT);
	if (a.rotate_cost + b.rev_cost == cost)
		return (ROTREV);
	return (NOT_FOUND);
}

t_type	ft_samedirection(t_cost a, t_cost b, size_t cost)
{
	if (ft_returngreater(a.rev_cost, b.rev_cost) == cost)
		return (REV);
	if (ft_returngreater(a.rotate_cost, b.rotate_cost) == cost)
		return (ROTATE);
	return (NOT_FOUND);
}

/* Finds the correct instruction combination
for getting A and B for the correct state for push */

t_type	ft_findtype(t_pair *pair)
{
	t_type	ret;

	ft_printf("Pair: %d %d\n", pair->stack_a.target, pair->stack_b.target);
	ft_printf("Pair Rev: %llu %llu\n", pair->stack_a.rev_cost, pair->stack_b.rev_cost);
	ft_printf("Pair Rot: %llu %llu\n", pair->stack_a.rotate_cost, pair->stack_b.rotate_cost);
	ft_printf("Pair Total cost: %llu\n", pair->total_cost);
	ret = ft_samedirection(pair->stack_a, pair->stack_b, pair->total_cost);
	if (ret > NOT_FOUND)
		return (ret);
	ret = ft_iscombination(pair->stack_a, pair->stack_b, pair->total_cost);
	if (ret > NOT_FOUND)
		return (ret);
	return (NOT_FOUND);
}

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

void	ft_generate_instructions(t_pair *pair)
{
	t_type	type;

	type = ft_findtype(pair);
	if (type == ROTATE)
		ft_gen_rotate(pair);
	else if (type == REV)
		ft_gen_rev(pair);
	else if (type == REVROT)
		ft_gen_revrot(pair);
	else if (type == ROTREV)
		ft_gen_rotrev(pair);
	else
	{
		ft_putstr("GEN INSTR ERROR!");
		ft_error();
	}
}