/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:01:37 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/08 16:52:14 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_correct(t_utils *utils)
{
	int		i;
	int		compare;
	t_node	*current;

	current = utils->head_a;
	i = 0;
	compare = INT_MIN;
	if (utils->count_b)
		return (0);
	while (current)
	{
		i++;
		if (compare > current->value)
			return (0);
		compare = current->value;
		current = current->next;
	}
	if (i != utils->input_count)
		return (0);
	return (1);
}
