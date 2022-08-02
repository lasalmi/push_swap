/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:32:17 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/02 11:14:36 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ft_print_list(t_utils utils)
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

void	ft_print_instruction(int instruction)
{
	const char	*table[] = {"sa", "sb", "ss", "pa", "pb", \
	"ra", "rb", "rr", "rra", "rrb", "rrr", NULL};

	ft_printf("%s\n", table[instruction]);
}

void	ft_print_action(int instruction)
{
	const char	*table[] = {"SWAPPING A", "SWAPPING B", "SWAPPING BOTH", \
	"PUSHING A", "PUSHING B", "ROTATING A", "ROTATING B", "ROTATING BOTH", \
	"REVERSE ROTATING A", "REVERSE ROTATING B", "REVERSE ROTATING BOTH", NULL};

	ft_printf("%s\n", table[instruction]);
}

void	ft_output(t_utils *utils, int instruction)
{
	if (utils->caller == PUSH_SWAP)
		ft_print_instruction(instruction);
	else if (utils->caller == PRINT)
	{
		ft_print_action(instruction);
		ft_print_list(*utils);
	}
}
