/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 03:05:00 by lasalmi           #+#    #+#             */
/*   Updated: 2022/09/12 08:40:44 by lasalmi          ###   ########.fr       */
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

void	check_argc(int *argc, char ***argv, int *splitted)
{
	size_t	i;

	i = 0;
	(*argv) += 1;
	*argc -= 1;
	if (*argc != 1)
	{
		*splitted = 0;
		return ;
	}
	*argv = ft_strsplit(**argv, ' ');
	while ((*argv)[i])
		i++;
	*argc = (int)i;
	*splitted = 1;
}

int	main(int argc, char **argv)
{
	t_utils	utils;
	int		splitted;

	initialize_utils(&utils);
	utils.caller = CHECKER;
	if (argc < 2)
		return (0);
	check_argc(&argc, &argv, &splitted);
	read_values(&utils, argv, argc);
	read_input(&utils);
	if (utils.caller == PRINT)
		print_stacks(utils);
	if (is_correct(&utils))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (splitted)
		ft_free_str_arr(&argv);
	free_stacks(&utils);
	return (0);
}
