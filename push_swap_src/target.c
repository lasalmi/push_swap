/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:31:07 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/21 16:21:30 by lasalmi          ###   ########.fr       */
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

/* Finds the closest member of the given chunk and returns the value
of that member, DOESNT return direction! */
int	ft_find_target_a(t_chunk chunk, t_node *head, t_node *tail)
{
	int	rotate;
	int	rev_rotate;
	int	rot_target;
	int	rev_target;

	rotate = 0;
	rev_rotate = 1;
	rot_target = head->value;
	rev_target = tail->value;
	while (!ft_is_in_range(head->value,chunk.start, chunk.end))
	{
		rotate++;
		head = head->next;
		rot_target = head->value;
	}
	while (!ft_is_in_range(tail->value,chunk.start, chunk.end))
	{
		rev_rotate++;
		tail = tail->prev;
		rev_target = tail->value;
	}
	if (rotate >= rev_rotate)
		return (rev_target);
	return (rot_target);
}
