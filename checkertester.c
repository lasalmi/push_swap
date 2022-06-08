/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkertester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:37:46 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/08 17:07:13 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (-1);
	time_t	t;
   srand((unsigned) time(&t));
	size_t amount = atoi(argv[1]);
	const char	*table[] = {"sa", "sb", "ss", "pa", "pb", \
	"ra", "rb", "rr", "rra", "rrb", "rrr", NULL};
	size_t i;
	while (amount--)
	{
		i = (rand() % 11);
		dprintf(1, "%s\n", table[i]);
	}
	return (0);
}
