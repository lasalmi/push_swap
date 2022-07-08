/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:47:37 by lasalmi           #+#    #+#             */
/*   Updated: 2022/07/08 15:04:55 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static int	is_smaller(int a, int b)
{
	return (a < b);
}

static void locator(t_utils *utils, t_node **node)
{
	t_node	*finder;

	finder = utils->head_a;
	while (finder && utils->sorted[0] != finder->value)
		finder = finder->next;
	*node = finder;
}

static void next_node(t_node **node, t_utils *utils)
{
	if ((*node)->next)
		*node = (*node)->next;
	else
		*node = utils->head_a;
}

static int compare_nodes(t_node node, t_utils *utils)
{
	if (node.next)
		return (is_smaller(node.value, node.next->value));
	else
		return (is_smaller(node.value, utils->head_a->value));
}

/* Checks that the stack A is in right order, but
doesnt check that it is correctly rotated */

int	in_order(t_utils *utils)
{
	t_node	*node;
	size_t	i;

	i = 0;
	locator(utils, &node);
	while (node && i < (utils->input_count - 1))
	{
		if (!compare_nodes(*node, utils))
			return (0);
		next_node(&node, utils);
		i++;
	}
	return (1);
}