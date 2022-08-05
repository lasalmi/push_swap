/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:47:37 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/05 13:27:36 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static int	is_smaller(int a, int b)
{
	return (a < b);
}

static void	locator(t_utils *utils, t_node **node)
{
	t_node	*finder;
	int		smallest;

	smallest = ft_find_smallest(utils->head_a);
	finder = utils->head_a;
	while (finder && smallest != finder->value)
		finder = finder->next;
	*node = finder;
}

static void	next_node(t_node **node, t_utils *utils)
{
	if ((*node)->next)
		*node = (*node)->next;
	else
		*node = utils->head_a;
}

static int	compare_nodes(t_node node, t_utils *utils)
{
	if (node.next)
		return (is_smaller(node.value, node.next->value));
	else
		return (is_smaller(node.value, utils->head_a->value));
}

/* Checks that the stack A is in right order, but
doesnt check that it is correctly rotated, utils->count_a - 1
because the last one doesnt need to be evaluated */

int	in_order(t_utils *utils)
{
	t_node	*node;
	size_t	i;

	i = 0;
	locator(utils, &node);
	while (node && i < (utils->count_a - 1))
	{
		if (!compare_nodes(*node, utils))
		{
			return (0);
		}
		next_node(&node, utils);
		i++;
	}
	return (1);
}
