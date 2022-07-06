/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:49:28 by lasalmi           #+#    #+#             */
/*   Updated: 2022/07/06 09:30:58 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ft_initutils(t_utils *utils)
{
	utils->input_count = -1;
	utils->head_a = NULL;
	utils->head_b = NULL;
	utils->tail_a = NULL;
	utils->tail_b = NULL;
	utils->count_a = 0;
	utils->count_b = 0;
	utils->instr_count = 0;
	utils->caller = INITIALIZER;
}

void	ft_initinstructions(t_instructions *instructions)
{
	instructions->inst_array = NULL;
	instructions->count = 0;
	instructions->memthreshold = 0;
}

void	ft_init_target(t_target *target)
{
	target->processed = 0;
	target->rotate_target = 0;
	target->rev_target = 1;
	target->rotate_cost = 0;
	target->rev_rot_cost = 0;
}
