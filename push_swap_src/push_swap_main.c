/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:41:02 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/15 13:51:45 by lasalmi          ###   ########.fr       */
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
	ft_quicksortint(arr, utils->input_count);
	return (arr);
}

ft_countcost(int value_to_find, t_utils *utils)
{
	int		i;
	int		j;
	t_node	*list;

	list = utils->head_a;
	while (value_to_find != list->value)
	{
		i++;
		list = list->next;
	}
	i++;
	list = utils->tail_a;
	while (value_to_find != list->value)
	{
		j--;
		list = list->prev;
	}
	if ()
}

int	main(int argc, char **argv)
{
	t_utils	utils;
	int		*sorted;

	ft_initutils(&utils);
	utils.head_b = NULL;
	if (argc < 2)
		ft_error();
	ft_read_values(&utils, argv + 1, argc - 1);
	sorted = ft_sortvalues(&utils);
	int i = 0;
	while (i < argc - 1)
		ft_printf("%d\n", sorted[i++]);
	ft_freelists(&utils);
	return (0);
}
