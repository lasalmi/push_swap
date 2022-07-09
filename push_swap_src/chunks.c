/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:57:30 by lasalmi           #+#    #+#             */
/*   Updated: 2022/07/09 11:18:37 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static size_t	ft_countchunks(t_utils *utils)
{
	if (utils->input_count <= 19)
		return (2);
	if (utils->input_count > 19 && utils->input_count <= 50)
		return (2);
	if (utils->input_count > 50 && utils->input_count <= 150)
		return (5);
	if (utils->input_count > 150)
		return (11);
	return (5);
}

static void	ft_initializechunk(t_chunk *chunk)
{
	chunk->start = 0;
	chunk->end = 0;
	chunk->sorted = 0;
	chunk->processed = 0;
}

static void	ft_allocatechunks(t_utils *utils, t_solver *solver)
{
	size_t	chunks;
	size_t	i;

	solver->chunk_amount = ft_countchunks(utils);
	chunks = solver->chunk_amount;
	i = 0;
	solver->chunks = (t_chunk *)malloc(sizeof(t_chunk) * chunks);
	while (i < chunks)
		ft_initializechunk(&solver->chunks[i++]);
}

static void	ft_setchunks(int *sorted, t_solver *solverutil, size_t first, size_t rest)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	solverutil->chunks[j].start = sorted[i++];
	while (i < first - 1)
		i++;
	solverutil->chunks[j].end = sorted[i++];
	j++;
	while (j < solverutil->chunk_amount && rest)
	{
		solverutil->chunks[j].start = sorted[i++];
		while (1)
		{
			solverutil->chunks[j].end = sorted[i];
			i++;
			if ((i - first) % rest == 0)
				break ;
		}
		j++;
	}
}

/* Identifies which chunk contains the nb given
and returns the index of that chunk */

int	ft_identifychunk(int n, t_chunk *chunks)
{
	int	i;

	i = 0;
	while (!ft_is_in_range(n, chunks[i].start, chunks[i].end))
		i++;
	return (i);
}

/* Counts the amount of integers in each chunk. The first one has the most */

void	ft_getchunks(t_utils *utils, t_solver *solver)
{
	size_t	first_chunk;
	size_t	other_chunks;

	ft_allocatechunks(utils, solver);
	first_chunk = utils->input_count / solver->chunk_amount;
	first_chunk += utils->input_count % solver->chunk_amount;
	other_chunks = utils->input_count / solver->chunk_amount;
	ft_setchunks(utils->sorted, solver, first_chunk, other_chunks);
}
