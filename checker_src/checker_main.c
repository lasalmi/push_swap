/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 03:05:00 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/06 11:48:53 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ft_read_input(t_utils *utils)
{
	int				ret;
	char			*line;
	t_instructions	instr;
	int				fd;

	if (utils->file)
		fd = open(utils->file, O_RDONLY);
	else
		fd = 0;
	ret = 1;
	ft_init_instructions(&instr);
	line = NULL;
	while (ret && fd >= 0)
	{
		ret = get_next_line(fd, &line);
		if (ret < 1)
			break ;
		ft_save_instruction(&instr, line);
		ft_strdel(&line);
	}
	if (ret < 0 || fd < 0)
		ft_error();
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
	if (ft_is_correct(&utils))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_lists(&utils);
	return (0);
}
