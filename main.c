/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 03:05:00 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/03 03:26:32 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "./libft/libft.h"

int main(void)
{
	t_node *head = ft_createnode();
	t_node *node2 = ft_createnode();
	t_node *node3 = ft_createnode();
	head->next = node2;
	node2->next = node3;
	node2->prev = head;
	node3->prev = node2;
	head->value = 1;
	node2->value = 2;
	node3->value = 3;
	t_node *current = head;
	while (current)
	{
		ft_printf("%i", current->value);
		current = current->next;
	}
	ft_swapnode(head, node3);
	current = node3;
	while (current)
	{
		ft_printf("%i", current->value);
		current = current->next;
	}
}
