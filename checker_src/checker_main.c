/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 03:05:00 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/08 13:31:21 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_instruction_error(t_utils *utils)
{
	ft_free_lists(utils);
	ft_error();
}

void	ft_read_input(t_utils *utils)
{
	int				ret;
	char			*line;
	t_instructions	instr;
	int				fd;

	fd = 0;
	if (utils->file)
		fd = open(utils->file, O_RDONLY);
	ft_init_instructions(&instr);
	line = NULL;
	while (fd >= 0)
	{
		ret = get_next_line(fd, &line);
		if (ret < 1)
			break ;
		ft_save_instruction(&instr, line);
		ft_strdel(&line);
		if (!instr.inst_array)
			ft_error();
	}
	if (ret < 0 || fd < 0)
		ft_instruction_error(utils);
	ft_exec_instructions(utils, &instr);
}

int	main(int argc, char **argv)
{
	t_utils	utils;

	ft_initialize_utils(&utils);
	utils.caller = CHECKER;
	if (argc < 2)
		return (0);
	ft_read_values(&utils, argv + 1, argc - 1);
	ft_read_input(&utils);
	if (utils.caller == PRINT)
		ft_print_list(utils);
	if (ft_is_correct(&utils))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_lists(&utils);
	return (0);
}
