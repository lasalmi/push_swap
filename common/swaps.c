/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:30:55 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/08 16:48:03 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_a(t_utils *utils)
{
	if (utils->count_a < 2)
		return ;
	ft_swap(&utils->head_a->value, &utils->head_a->next->value);
}

void	ft_swap_b(t_utils *utils)
{
	if (utils->count_b < 2)
		return ;
	ft_swap(&utils->head_b->value, &utils->head_b->next->value);
}

void	ft_swap_both(t_utils *utils)
{
	ft_swap_a(utils);
	ft_swap_b(utils);
}

void	rotate_both(t_utils *utils)
{
	rotate_a(utils);
	rotate_b(utils);
}

void	rev_rotate_both(t_utils *utils)
{
	rev_rotate_a(utils);
	rev_rotate_b(utils);
}
