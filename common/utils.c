/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:28:32 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/08 16:56:06 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Frees both lists in utils. After reaching the
end of stack_a, will switch to head_b if it
exists. Uses the head_a pointer for freeing stack_b
aswell. Use only when program is finishing */

void	free_stacks(t_utils *utils)
{
	t_node	*temp;

	temp = NULL;
	while (utils->head_a)
	{
		temp = utils->head_a->next;
		free(utils->head_a);
		utils->head_a = NULL;
		utils->head_a = temp;
	}
	while (utils->head_b)
	{
		temp = utils->head_b->next;
		free(utils->head_b);
		utils->head_b = NULL;
		utils->head_b = temp;
	}
}
