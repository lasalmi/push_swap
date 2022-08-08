/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:57:35 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/08 12:33:18 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

/* Loads the values from the original head_a
into an array of ints. All the integers need
to be in stack A */
void	ft_loadvalues(t_utils *utils)
{
	t_node	*list;
	int		*arr;

	arr = utils->sorted;
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
void	ft_sortvalues(t_utils *utils)
{
	utils->sorted = (int *)malloc(sizeof(int) * utils->input_count);
	if (!utils->sorted)
	{
		ft_free_lists(utils);
		exit(2);
	}
	ft_loadvalues(utils);
	ft_quicksortint(utils->sorted, utils->input_count);
}
