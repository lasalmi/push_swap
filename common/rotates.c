/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:29:02 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/07 14:40:55 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ft_rev_rotate_a(t_utils *utils)
{
	t_node	*new_tail;
	t_node	*new_head;

	if (utils->count_a < 2)
		return ;
	new_tail = utils->tail_a->prev;
	new_head = utils->tail_a;
	new_tail->next = NULL;
	new_head->next = utils->head_a;
	new_head->prev = NULL;
	utils->head_a->prev = new_head;
	utils->tail_a->next = utils->head_a;
	utils->head_a = new_head;
	utils->tail_a = new_tail;
}

void	ft_rev_rotate_b(t_utils *utils)
{
	t_node	*temp;

	if (utils->count_b < 2)
		return ;
	temp = utils->tail_b->prev;
	utils->tail_b->next = utils->head_b;
	utils->tail_b->prev->next = NULL;
	utils->head_b->prev = utils->tail_b;
	utils->head_b = utils->tail_b;
	utils->tail_b = temp;
	utils->head_b->prev = NULL;
}

void	ft_rotate_a(t_utils *utils)
{
	t_node	*temp;

	if (utils->count_a < 2)
		return ;
	temp = utils->head_a->next;
	utils->tail_a->next = utils->head_a;
	utils->head_a->prev = utils->tail_a;
	utils->head_a->next = NULL;
	utils->tail_a = utils->head_a;
	temp->prev = NULL;
	utils->head_a = temp;
}

void	ft_rotate_b(t_utils *utils)
{
	t_node	*temp;

	if (utils->count_b < 2)
		return ;
	temp = utils->head_b->next;
	utils->tail_b->next = utils->head_b;
	utils->head_b->prev = utils->tail_b;
	utils->head_b->next = NULL;
	utils->tail_b = utils->head_b;
	temp->prev = NULL;
	utils->head_b = temp;
}
