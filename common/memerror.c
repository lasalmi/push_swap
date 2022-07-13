/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memerror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:28:02 by lasalmi           #+#    #+#             */
/*   Updated: 2022/07/13 12:36:15 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void mallocfail(t_utils *utils)
{
	ft_freelists(utils);
	exit(2);
}