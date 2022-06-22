/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:32:17 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/22 17:42:13 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ft_printlist(t_utils utils)
{
	ft_printf("STACK A:%i  STACK  B:%i\n", utils.count_a, utils.count_b);
	while (utils.head_a || utils.head_b)
	{
		if (utils.head_a)
		{
			ft_printf("%9i|", utils.head_a->value);
			utils.head_a = utils.head_a->next;
		}
		else
			ft_printf("         |");
		if (utils.head_b)
		{
			ft_printf(" %i", utils.head_b->value);
			utils.head_b = utils.head_b->next;
		}
		ft_printf("\n");
	}
}
