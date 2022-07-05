/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:06:43 by lasalmi           #+#    #+#             */
/*   Updated: 2022/07/05 08:40:51 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ft_checklistprev(t_node *node)
{
	int	i;

	i = 0;
	while (node && i < 500)
	{
		i++;
		if (node->prev && node->prev->next != node)
			ft_printf("Error in prev->next\n");
		node = node->prev;
	}
	if (i > 499)
		ft_printf("Index gets too high\n");
}

void	ft_checklistnext(t_node *node)
{
	int	i;

	i = 0;
	while (node && i < 500)
	{
		i++;
		if (node->next && node->next->prev != node)
			ft_printf("Error in next->prev\n");
		node = node->next;
	}
	if (i > 499)
		ft_printf("Index gets too high\n");
}

void	ft_check_list(t_utils *utils)
{
	ft_checklistnext(utils->head_a);
	ft_checklistprev(utils->tail_a);
	ft_checklistnext(utils->head_b);
	ft_checklistprev(utils->tail_b);
}
