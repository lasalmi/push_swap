/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:31:07 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/21 11:39:19 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

/* Finds the target for the push in list */

int	ft_findslotb(int nb, t_node *head)
{
	int	diff;
	int	ret;

	ret = 0;
	diff = INT_MIN;
	while (head)
	{
		if ((nb - head->value) > diff && (nb - head->value) > 0)
		{
			diff = nb - head->value;
			ret = head->value;
		}
		head = head->next;
	}
	return (ret);
}
