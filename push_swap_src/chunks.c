/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:57:30 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/20 17:13:52 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

size_t	ft_countchunks(t_utils *utils)
{
	if (utils->input_count <= 19)
		return (1);
	if (utils->input_count > 19 && utils->input_count <= 50)
		return (2);
	if (utils->input_count > 50 && utils->input_count <= 150)
		return (5);
	if (utils->input_count > 150)
		return (11);
}

void	ft_initializechunk(t_chunk *chunk)
{
	chunk->start = 0;
	chunk->end = 0;
	chunk->sorted = 0;
}

void	ft_allocatechunks(t_utils *utils, t_solver *solver)
{
	size_t	chunks;
	size_t	i;

	chunks = ft_countchunks(utils);
	i = 0;
	solver->chunks = (t_chunk *)malloc(sizeof(t_chunk) * chunks);
	while (i < chunks)
		ft_initializechunk(&solver->chunks[i++]);
}
