/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:49:28 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/07 15:39:44 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ft_initialize_utils(t_utils *utils)
{
	utils->input_count = -1;
	utils->head_a = NULL;
	utils->head_b = NULL;
	utils->tail_a = NULL;
	utils->tail_b = NULL;
	utils->count_a = 0;
	utils->count_b = 0;
	utils->caller = INITIALIZER;
	utils->file = NULL;
}

void	ft_init_instructions(t_instructions *instructions)
{
	instructions->inst_array = NULL;
	instructions->count = 0;
	instructions->memthreshold = 0;
}

void	ft_initialize_target(t_trgt	*cost)
{
	cost->target = 0;
	cost->rev_cost = 0;
	cost->rotate_cost = 0;
	cost->found = 0;
}
