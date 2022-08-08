/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:32:17 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/08 11:37:27 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stacks(t_utils utils)
{
	ft_printf("STACK A:%i  STACK  B:%i\n", utils.count_a, utils.count_b);
	while (utils.head_a || utils.head_b)
	{
		if (utils.head_a)
		{
			ft_printf("%9i|", utils.head_a->value);
			utils.head_a = utils.head_a->next;
		}
		else
			ft_printf("         |");
		if (utils.head_b)
		{
			ft_printf(" %i", utils.head_b->value);
			utils.head_b = utils.head_b->next;
		}
		ft_printf("\n");
	}
}

void	print_instruction(int instruction)
{
	const char	*table[] = {"sa", "sb", "ss", "pa", "pb", \
	"ra", "rb", "rr", "rra", "rrb", "rrr", NULL};

	ft_printf("%s\n", table[instruction]);
}

void	print_action(int instruction)
{
	const char	*table[] = {"ft_swapPING A", "ft_swapPING B", "ft_swapPING BOTH", \
	"PUSHING A", "PUSHING B", "ROTATING A", "ROTATING B", "ROTATING BOTH", \
	"REVERSE ROTATING A", "REVERSE ROTATING B", "REVERSE ROTATING BOTH", NULL};

	ft_printf("%s\n", table[instruction]);
}

void	output(t_utils *utils, int instruction)
{
	if (utils->caller == PUSH_ft_swap)
		print_instruction(instruction);
	else if (utils->caller == PRINT)
	{
		print_action(instruction);
		print_stacks(*utils);
	}
}
