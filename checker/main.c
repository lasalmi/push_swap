/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 03:05:00 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/03 13:57:24 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "./libft/libft.h"
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
		current->value = ft_atol(argv[i]);
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
	t_node	*head;

	head = ft_read_values(argv + 1, argc - 1);
	while (head)
	{
		ft_printf("%i", head->value);
		head = head->next;
	}
	return (0);
}
