/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:55:11 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/08 11:37:27 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_get_instruction(char *line)
{
	const char	*table[] = {"sa", "sb", "ss", "pa", "pb", \
	"ra", "rb", "rr", "rra", "rrb", "rrr", NULL};
	int			i;

	i = 0;
	if (!line)
		return (-1);
	while (table[i])
	{
		if (!ft_strcmp(line, table[i]))
			return (i);
		i++;
	}
	return (-1);
}

void	ft_exec_instructions(t_utils *utils, t_instructions *instr)
{
	size_t	i;

	i = 0;
	while (i < instr->count)
	{
		ft_pw_dispatcher(utils, instr->inst_array[i]);
		if ((utils->head_a && utils->head_a->prev) \
	|| (utils->head_b && utils->head_b->prev))
			exit(1);
		i++;
	}
	free(instr->inst_array);
	if (utils->caller == PRINT)
		ft_printf("Instructions: %llu\n", instr->count);
}

static void	realloc_instructions(t_instructions *instr, size_t i)
{
	int	*temp;

	temp = (int *)malloc(sizeof(int) * instr->memthreshold * 4);
	if (!temp)
		ft_error();
	ft_memcpy(temp, instr->inst_array, (i * sizeof(int)));
	free(instr->inst_array);
	instr->memthreshold *= 2;
	instr->inst_array = temp;
}

/* Initializes the instruction array if it doesnt exist, if
index goes over memthreshold allocates new memory and copies
the memory to the new alloocation */
void	ft_save_instruction(t_instructions *instr, char *line)
{
	static size_t	i;

	if (!instr->inst_array)
	{
		instr->inst_array = (int *)malloc(sizeof(int) * 20);
		if (!instr->inst_array)
			ft_error();
		instr->memthreshold = 20 / 2;
	}
	instr->inst_array[i] = ft_get_instruction(line);
	if (instr->inst_array[i] < 0)
		ft_error();
	i++;
	instr->count = i;
	if (i > instr->memthreshold)
		realloc_instructions(instr, i);
}
