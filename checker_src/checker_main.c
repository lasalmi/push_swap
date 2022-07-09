/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 03:05:00 by lasalmi           #+#    #+#             */
/*   Updated: 2022/07/09 15:16:45 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	ft_get_instruction(char *line)
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

/* Initializes the instruction array if it doesnt exist, if
index goes over memthreshold allocates new memory and copies
the memory to the new alloocation */
void	ft_save_instruction(t_instructions *instr, char *line)
{
	static size_t	i;
	static size_t	alloc_size;
	int				*temp;

	if (!instr->inst_array)
	{
		instr->inst_array = (int *)malloc(sizeof(int) * 20);
		instr->memthreshold = 20 / 2;
	}
	instr->inst_array[i] = ft_get_instruction(line);
	if (instr->inst_array[i] < 0)
		ft_error();
	i++;
	instr->count = i;
	if (i > instr->memthreshold)
	{
		temp = (int *)malloc(sizeof(int) * instr->memthreshold * 4);
		if (!temp)
			ft_error();
		ft_memcpy(temp, instr->inst_array, (i * sizeof(int)));
		free(instr->inst_array);
		instr->memthreshold *= 2;
		instr->inst_array = temp;
	}
}

void	ft_read_input(t_utils *utils)
{
	int				ret;
	char			*line;
	int				func;
	t_instructions	instr;

	ret = 1;
	ft_initinstructions(&instr);
	line = NULL;
	while (ret)
	{
		ret = get_next_line(0, &line);
		if (ret < 1)
			break ;
		ft_save_instruction(&instr, line);
		ft_strdel(&line);
	}
	if (ret < 0)
		ft_error();
	ft_exec_instructions(utils, &instr);
}

int	main(int argc, char **argv)
{
	t_utils	utils;

	ft_initutils(&utils);
	utils.caller = CHECKER;
	utils.head_b = NULL;
	if (argc < 2)
		return (0);
	ft_read_values(&utils, argv + 1, argc - 1);
	ft_read_input(&utils);
	if (ft_is_correct(&utils))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_freelists(&utils);
	return (0);
}