/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:31:07 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/23 00:24:11 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

/* Finds the target for the push in list, aka the
integer that needs to be at the top of the stack B
when pushing int nb */

int	ft_find_target_b(int nb, t_node *head)
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

static int	ft_find_rotate(t_chunk *chunk, t_node *head, int *rotate)
{
	int	target;
	int	cost;

	target = head->value;
	cost = 0;
	while (head && !ft_is_in_range(head->value,chunk->start, chunk->end))
	{
		cost++;
		head = head->next;
		if (head)
			target = head->value;
	}
	if (!head)
		chunk->processed = 1;
	*rotate = cost;
	return (target);
}

static int	ft_find_rev_rotate(t_chunk *chunk, t_node *tail, int *rotate)
{
	int	target;
	int	cost;

	target = tail->value;
	cost = 0;
	while (tail && !ft_is_in_range(tail->value,chunk->start, chunk->end))
	{
		cost++;
		tail = tail->prev;
		if (tail)
			target = tail->value;
	}
	if (!tail)
		chunk->processed = 1;
	*rotate += cost;
	return (target);
}

void	ft_get_target_costs(t_target *target, t_utils *utils)
{
	target->rotate_cost = ft_countcost_a(target->rotate_target, utils);
	target->rev_rot_cost = ft_countcost_a(target->rev_target, utils);
	target->rotate_pair = ft_find_target_b(target->rotate_target, utils->head_b);
	target->rev_pair = ft_find_target_b(target->rev_target, utils->head_b);
	target->rev_pair_cost = ft_countcost_b(target->rev_pair, utils);
	target->rot_pair_cost = ft_countcost_b(target->rotate_pair, utils);
	ft_printf("Rot target: %d Rot cost: %d Rot pair: %d\n", target->rotate_target, target->rotate_cost, target->rotate_pair);
	ft_printlist(*utils);
}

/* Finds the closest member of the given chunk and returns the value
of that member, DOESNT return direction! */
t_target	ft_find_closest_a(t_chunk *chunk, t_node *head, t_node *tail)
{
	t_target	target;

	ft_init_target(&target);
	if (!head)
	{
		chunk->processed = 1;
		return (target);
	}
	target.rotate_target = head->value;
	target.rev_target = tail->value;
/*	while (head && !ft_is_in_range(head->value,chunk->start, chunk->end))
	{
		rotate++;
		head = head->next;
		if (head)
			rot_target = head->value;
	}
	if (!head)
		chunk->processed = 1; */
	target.rotate_target = ft_find_rotate(chunk, head, &target.rotate_target);
	if (chunk->processed)
		target.processed = 1;
	target.rev_target = ft_find_rev_rotate(chunk, tail, &target.rev_target);
/*	while (tail && head  && !ft_is_in_range(tail->value,chunk->start, chunk->end))
	{
		rev_rotate++;
		tail = tail->prev;
		rev_target = tail->value;
	} */
	return (target);
}
