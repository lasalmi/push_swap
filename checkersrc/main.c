/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 03:05:00 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/03 18:40:10 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"
#include <limits.h>

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

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
static void ft_checkduplicate(int value, t_node *list)
{
	while (list)
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
	char *temp;
	long long result;

	temp = str;
	if (ft_strlen(str) > 11 || !ft_isnumber(str))
		ft_error();
	result = ft_atoll(str);
	if (result < INT_MIN || result > INT_MAX)
		ft_error();
	ft_checkduplicate((int)result, list);
	return ((int)result);
}

/* Reads values from input. TODO: Replace
ft_atol with input validator, add node add */

t_node	*ft_read_values(char **argv, int argc)
{
	t_node	*head;
	t_node	*current;
	int		i;

	i = 0;
	head = ft_createnode();
	current = head;
	while (i < argc)
	{
		current->value = ft_validate_input(argv[i], head);
		if (i == argc - 1)
			break;
		current->next = ft_createnode();
		current = current->next;
		i++;
	}
	return (head);
}

int main(int argc, char **argv)
{
	t_utils	utils;

	utils.head_a = ft_read_values(argv + 1, argc - 1);
	//ft_swapnode(utils.head_a->next, utils.head_a->next->next);
	ft_printlist(utils.head_a);
	return (0);
}
