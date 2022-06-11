/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:41:02 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/11 15:34:47 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

/* Loads the values from the original head_a
into an array of ints. All the integers need
to be in stack A */
void ft_loadvalues(t_utils *utils, int *arr)
{
	t_node	*list;

	list = utils->head_a;
	while (list)
	{
		*arr = list->value;
		list = list->next;
		arr++;
	}
}
/* Loads and sorts the values in the double linked list
into an array of integers */
int	*ft_sortvalues(t_utils *utils)
{
	int	*arr;

	arr = (int *)malloc(sizeof(int) * utils->input_count);
	ft_loadvalues(utils, arr);
}

int	main(int argc, char **argv)
{
	t_utils	utils;
	int		*order;

	ft_initutils(&utils);
	utils.head_b = NULL;
	if (argc < 2)
		ft_error();
	ft_read_values(&utils, argv + 1, argc - 1);
	ft_printlist(utils);
	ft_freelists(&utils);
	return (0);
}
