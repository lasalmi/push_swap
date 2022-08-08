/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:55:11 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/08 16:52:14 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_instruction(char *line)
{
	const char	*table[] = {"sa", "sb", "ss", "pa", "pb", \
	"ra", "rb", "rr", "rra", "rrb", "rrr", NULL};
	int			i;

	i = 0;
	if (!line)
		return (-1);
	while (table[i])
	{
		if (!strcmp(line, table[i]))
			return (i);
		i++;
	}
	return (-1);
}

void	exec_instructions(t_utils *utils, t_instructions *instr)
{
	size_t	i;

	i = 0;
	while (i < instr->count)
	{
		pw_dispatcher(utils, instr->inst_array[i]);
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
	{
		free(instr->inst_array);
		instr->inst_array = NULL;
		return ;
	}
	memcpy(temp, instr->inst_array, (i * sizeof(int)));
	free(instr->inst_array);
	instr->memthreshold *= 2;
	instr->inst_array = temp;
}

/* Initializes the instruction array if it doesnt exist, if
index goes over memthreshold allocates new memory and copies
the memory to the new alloocation. Sets instr->array
to NULL in case of malloc failure */
void	save_instruction(t_instructions *instr, char *line)
{
	static size_t	i;

	if (!instr->inst_array)
	{
		instr->inst_array = (int *)malloc(sizeof(int) * 20);
		if (!instr->inst_array)
			return ;
		instr->memthreshold = 20 / 2;
	}
	instr->inst_array[i] = get_instruction(line);
	if (instr->inst_array[i] < 0)
	{
		free(instr->inst_array);
		instr->inst_array = NULL;
		return ;
	}
	i++;
	instr->count = i;
	if (i > instr->memthreshold)
		realloc_instructions(instr, i);
}
