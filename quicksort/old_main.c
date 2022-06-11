/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:04:18 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/11 15:43:00 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *array, int left, int right)
{
	int temp;

	temp = array[left];
	array[left] = array[right];
	array[right] = temp;
}

int ft_partition(int *array, int left, int right, int pivot)
{
	while (left <= right)
	{
		while (array[left] < pivot)
			left++;
		while (array[right] > pivot)
			right--;
		if (left <= right)
		{
			ft_swap(array, left, right);
			left++;
			right--;
		}
	}
	return (left);
}

void ft_printarray(int *array)
{
	size_t i = 0;
	while (i < 9)
		printf("%i,", array[i++]);
	printf("\n");
}

void	ft_quicksort(int *array, int left, int right)
{
	int	pivot;
	int	index;

	if (left >= right)
		return ;
	pivot = array[(left + right) / 2];
	index = ft_partition(array, left, right, pivot);
	printf("Left: %i  Right%i Index:%i \n", left, right, index);
	ft_printarray(array);
	ft_quicksort(array, left, index - 1);
	ft_quicksort(array, index, right);
}
int main(void)
{
	int array[] = {5, 13, 9, 3, 10, 4, 6, 11, 19};
	
	ft_quicksort(array, 0, 8);
	int i = 0;
}