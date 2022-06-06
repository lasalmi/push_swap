/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:10:17 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/06 14:15:10 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ft_create_elem_stack_a(t_utils *utils)
{
	t_node *new_node;

	new_node = ft_createnode();
	ft_add_node_tail(&utils->tail_a, new_node);
}