/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:16:10 by lasalmi           #+#    #+#             */
/*   Updated: 2022/08/08 16:52:14 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pw_dispatcher(t_utils *utils, int func_index)
{
	static const t_func	funcs[] = {ft_swap_a, ft_swap_b, ft_swap_both, \
	push_a, push_b, rotate_a, rotate_b, rotate_both, \
	rev_rotate_a, rev_rotate_b, rev_rotate_both};

	if (func_index < 0)
		error();
	output(utils, func_index);
	funcs[func_index](utils);
}
