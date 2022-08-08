/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:29:10 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/08 13:55:41 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Checks that value is not already in the list for duplicate
input */

static int	ft_checkduplicate(int value, t_node *list)
{
	while (list->next)
	{
		if (value == list->value)
			return (0);
		list = list->next;
	}
	return (1);
}
/* Checks strlen and int limits for int overflow protection, that it 
contains a valid number representation */

static int	ft_validate_input(char *str, t_node *list)
{
	char		*temp;
	long long	result;

	temp = str;
	if (ft_strlen(str) > 11 || !ft_is_number(str))
		return (0);
	result = ft_atoll(str);
	if (result < INT_MIN || result > INT_MAX)
		return (0);
	return (ft_checkduplicate((int)result, list));
}

void	ft_check_flag(t_utils *utils, char ***argv, int *argc)
{
	while (1)
	{
		if (*argc && utils->caller == CHECKER && ft_strequ(**argv, "-p"))
		{
			if (utils->caller == PRINT)
				ft_error();
			*argv = *argv + 1;
			*argc = *argc - 1;
			utils->caller = PRINT;
		}
		else if (*argc && utils->caller == CHECKER \
		&& ft_strequ(**argv, "-fi"))
		{
			if (utils->file)
				ft_error();
			*argv = *argv + 1;
			utils->file = **argv;
			*argv = *argv + 1;
			*argc = *argc - 2;
		}
		else if (*argc < 0)
			ft_error();
		else
			break ;
	}
}

void	save_to_node(t_utils *utils, char *arg, t_node *node)
{
	if (!ft_validate_input(arg, utils->head_a))
	{
		ft_free_lists(utils);
		ft_error();
	}
	node->value = ft_atoi(arg);
}

/* Reads values from input. TODO: Replace
ft_atol with input validator, add node add */

void	ft_read_values(t_utils *utils, char **argv, int argc)
{
	t_node	*current;
	int		i;

	i = 0;
	ft_check_flag(utils, &argv, &argc);
	utils->head_a = ft_create_node();
	if (!utils->head_a)
		exit (2);
	current = utils->head_a;
	utils->tail_a = current;
	utils->input_count = argc;
	while (i < argc)
	{
		save_to_node(utils, argv[i], current);
		if (i == argc - 1)
			break ;
		current = ft_create_elem_stack_a(utils);
		i++;
	}
	if (i == 0)
	{
		ft_free_lists(utils);
		exit(1);
	}
	utils->count_a = argc;
}
