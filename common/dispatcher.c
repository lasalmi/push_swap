/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:16:10 by lasalmi           #+#    #+#             */
/*   Updated: 2022/07/06 09:29:11 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ft_pw_dispatcher(t_utils *utils, int func_index)
{
	static const t_func	funcs[] = {ft_swap_a, ft_swap_b, ft_swap_both, \
	ft_push_a, ft_push_b, ft_rotate_a, ft_rotate_b, ft_rotate_both, \
	ft_rev_rotate_a, ft_rev_rotate_b, ft_rev_rotate_both};

	if (func_index < 0)
		ft_error();
	ft_output(utils, func_index);
	funcs[func_index](utils);
}
