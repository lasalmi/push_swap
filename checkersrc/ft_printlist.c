/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:32:17 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/06 18:24:32 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"
#include "../libft/libft.h"

void	ft_printlist(t_utils utils)
{
	ft_printf("STACK A:  STACK  B\n" );
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
