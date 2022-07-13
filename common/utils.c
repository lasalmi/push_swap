/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:28:32 by lasalmi           #+#    #+#             */
/*   Updated: 2022/07/13 12:56:43 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

/* Frees both lists in utils. After reaching the
end of stack_a, will switch to head_b if it
exists. Uses the head_a pointer for freeing stack_b
aswell. Use only when program is finishing */

void	ft_freelists(t_utils *utils)
{
	t_node	*temp;

	temp = NULL;
	while (utils->head_a)
	{
		temp = utils->head_a->next;
		free(utils->head_a);
		utils->head_a = NULL;
		utils->head_a = temp;
	}
	while (utils->head_b)
	{
		temp = utils->head_b->next;
		free(utils->head_b);
		utils->head_b = NULL;
		utils->head_b = temp;
	}
}

/* Gets the addresses of the tails of both stacks */
static void	ft_get_tails(t_utils *copy)
{
	t_node	*tail_a;
	t_node	*tail_b;

	tail_a = copy->head_a;
	tail_b = copy->head_b;
	while (tail_a && tail_a->next)
		tail_a = tail_a->next;
	while (tail_b && tail_b->next)
		tail_b = tail_b->next;
	copy->tail_a = tail_a;
	copy->tail_b = tail_b;
}
/* Copies the given dual linked lists to dst from
src. Copylist will break the copying if mallocfail occurs
and countnodes will check that the node counts match */
void	ft_copyutils(t_utils *dst, t_utils *src)
{
	dst->count_a = src->count_a;
	dst->count_b = src->count_b;
	dst->input_count = src->input_count;
	dst->sorted = src->sorted;
	dst->head_a = ft_copylist(src->head_a);
	dst->head_b = ft_copylist(src->head_b);
	if (countnodes(dst->head_a) != dst->count_a || \
	countnodes(dst->head_b) != dst->count_b)
	{
		ft_freelists(dst);
		mallocfail(src);
	}
	ft_get_tails(dst);
}

t_utils	ft_copystate(t_utils *original)
{
	t_utils	copy;

//	copy = (t_utils *)malloc(sizeof(t_utils));
	ft_copyutils(&copy, original);
	return (copy);
}
