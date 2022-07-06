/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:29:10 by lasalmi           #+#    #+#             */
/*   Updated: 2022/07/06 12:40:01 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

/* Checks that string is a number and only a number */

static int	ft_isnumber(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str != '\0')
		return (0);
	return (1);
}

/* Checks that value is not already in the list for duplicate
input */

static void	ft_checkduplicate(int value, t_node *list)
{
	while (list->next)
	{
		if (value == list->value)
			ft_error();
		list = list->next;
	}
}
/* Checks strlen and int limits for int overflow protection, that it 
contains a valid number representation */

static int	ft_validate_input(char *str, t_node *list)
{
	char		*temp;
	long long	result;

	temp = str;
	if (ft_strlen(str) > 11 || !ft_isnumber(str))
		ft_error();
	result = ft_atoll(str);
	if (result < INT_MIN || result > INT_MAX)
		ft_error();
	ft_checkduplicate((int)result, list);
	return ((int)result);
}

void	ft_check_flag(t_utils *utils, char ***argv, int *argc)
{
	if (utils->caller != CHECKER || !ft_strequ(**argv, "-p"))
		return ;
	*argv = *argv + 1;
	*argc = *argc - 1;
	utils->caller = PRINT;
}

/* Reads values from input. TODO: Replace
ft_atol with input validator, add node add */

void	ft_read_values(t_utils *utils, char **argv, int argc)
{
	t_node	*current;
	int		i;

	i = 0;
	ft_check_flag(utils, &argv, &argc);
	utils->head_a = ft_createnode();
	current = utils->head_a;
	utils->tail_a = current;
	utils->input_count = argc;
	while (i < argc)
	{
		current->value = ft_validate_input(argv[i], utils->head_a);
		if (i == argc - 1)
			break ;
		current = ft_create_elem_stack_a(utils);
		i++;
	}
	utils->count_a = argc;
}
