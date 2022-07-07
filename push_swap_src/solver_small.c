/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:55:59 by lasalmi           #+#    #+#             */
/*   Updated: 2022/07/07 12:06:19 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static	int	ft_are_consecutive(t_utils *utils, int a, int b)
{
	size_t	i;
	uint8_t	consecutive;

	consecutive = 0;
	i = 0;
	while (i < utils->input_count && utils->sorted[i] != a)
		i++;
	if (i > 0 && i < (utils->input_count - 1))
		return (b == utils->sorted[i - 1] || b == utils->sorted[i + 1]);
	if (i == (utils->input_count - 1) && i > 0)
		return (b == utils->sorted[i - 1] && b == utils->sorted[0]);
	if (i == 0)
		return (b == utils->sorted[i + 1] || b == utils->sorted[utils->input_count - 1]);
	return (0);
}
