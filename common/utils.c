/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:28:32 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/11 14:28:42 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

/* Frees both lists in utils. After reaching the
end of stack_a, will switch to head_b if it
exists. Uses the head_a pointer for freeing stack_b
aswell. Use only when program is finishing */

void	ft_freelists(t_utils *utils)
{
	t_node	*temp;

	temp = NULL;
	while (utils->head_a)
	{
		temp = utils->head_a->next;
		free(utils->head_a);
		utils->head_a = NULL;
		if (!temp && utils->head_b)
		{
			temp = utils->head_b;
			utils->head_b = NULL;
		}
		utils->head_a = temp;
	}
}