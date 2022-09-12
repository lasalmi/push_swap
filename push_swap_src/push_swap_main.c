/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:41:02 by lasalmi           #+#    #+#             */
/*   Updated: 2022/09/12 08:40:17 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Counts the cost of moving the value to the
top of the stack A. Returns negative,
if it is more efficient to use reverse rotate, returns 0
if already on top of stack A */
int	count_trgt_a(int value_to_find, t_utils *utils)
{
	int		i;
	int		j;
	t_node	*list;

	list = utils->head_a;
	i = 0;
	j = 0;
	if (!list)
		return (0);
	while (value_to_find != list->value)
	{
		i++;
		list = list->next;
	}
	list = utils->tail_a;
	while (value_to_find != list->value)
	{
		j--;
		list = list->prev;
	}
	j--;
	if (ft_abs(j) > i)
		return (i);
	return (j);
}

void	process(t_utils *utils)
{
	if (is_correct(utils))
		return ;
	solver_large(utils);
}

void	check_argc(int *argc, char ***argv, int *splitted)
{
	size_t	i;

	i = 0;
	(*argv) += 1;
	*argc -= 1;
	if (*argc != 1)
	{
		*splitted = 0;
		return ;
	}
	*argv = ft_strsplit(**argv, ' ');
	while ((*argv)[i])
		i++;
	*argc = (int)i;
	*splitted = 1;
}

int	main(int argc, char **argv)
{
	t_utils	utils;
	int		splitted;

	initialize_utils(&utils);
	utils.caller = PUSH_ft_swap;
	utils.head_b = NULL;
	if (argc < 2)
		return (0);
	check_argc(&argc, &argv, &splitted);
	read_values(&utils, argv, argc);
	sort_values(&utils);
	process(&utils);
	free(utils.sorted);
	free_stacks(&utils);
	if (splitted == 1)
		ft_free_str_arr(&argv);
	return (0);
}
