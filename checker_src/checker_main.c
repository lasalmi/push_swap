/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 03:05:00 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/08 16:56:54 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	instruction_error(t_utils *utils)
{
	free_stacks(utils);
	error();
}

void	read_input(t_utils *utils)
{
	int				ret;
	char			*line;
	t_instructions	instr;
	int				fd;

	fd = 0;
	if (utils->file)
		fd = open(utils->file, O_RDONLY);
	init_instructions(&instr);
	line = NULL;
	while (fd >= 0)
	{
		ret = get_next_line(fd, &line);
		if (ret < 1)
			break ;
		save_instruction(&instr, line);
		ft_strdel(&line);
		if (!instr.inst_array)
			error();
	}
	if (ret < 0 || fd < 0)
		instruction_error(utils);
	exec_instructions(utils, &instr);
}

int	main(int argc, char **argv)
{
	t_utils	utils;

	initialize_utils(&utils);
	utils.caller = CHECKER;
	if (argc < 2)
		return (0);
	read_values(&utils, argv + 1, argc - 1);
	read_input(&utils);
	if (utils.caller == PRINT)
		print_stacks(utils);
	if (is_correct(&utils))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stacks(&utils);
	return (0);
}
