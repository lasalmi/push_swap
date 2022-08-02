/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 03:05:00 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/02 13:18:48 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ft_read_input(t_utils *utils)
{
	int				ret;
	char			*line;
	int				func;
	t_instructions	instr;

	ret = 1;
	ft_init_instructions(&instr);
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

	ft_initialize_utils(&utils);
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
	ft_free_lists(&utils);
	return (0);
}
