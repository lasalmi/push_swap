/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:32:17 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/03 18:34:07 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"
#include "../libft/libft.h"

void	ft_printlist(t_node *list)
{
	while (list)
	{
		ft_printf("%i\n", list->value);
		list = list->next;
	}
}
