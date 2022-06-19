/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 16:03:59 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/11 17:21:48 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	ft_quicksortint(int *arr, int len);
void	quicksort_recursion(int *arr, int low, int high);
void	ft_swap(int *a, int *b);
int	partition(int *arr, int low, int high);

#include <stdio.h>

int issmaller(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}
int	main(void)
{
	int arr[] = {3, 14, 48, 5, 4, 11, 46, 31, 24, 19, 11};
	int arr2[] = {3, 14, 48, 5, 4, 11, 46, 31, 24, 19, 11};
	int len = 11;
	int i = 0;
	ft_quicksortint(arr, 11);
	qsort(arr2, 11, sizeof(int), &issmaller);
	printf("%i",memcmp(arr, arr2, sizeof(int) * 11));
	while (i < len)
		printf("%d ", arr2[i++]);
}

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_quicksortint(int *arr, int len)
{
	quicksort_recursion(arr, 0, len - 1);
}

int	partition(int *arr, int low, int high)
{
	int	i;
	int	j;
	int		pivot;

	i = low;
	j = low;
	pivot = arr[high];
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			ft_swap(&arr[j], &arr[i]);
			i++;
		}
		j++;
	}
	ft_swap(&arr[i], &arr[high]);
	return (i);
}

void	quicksort_recursion(int *arr, int low, int high)
{
	int	pivot_index;

	if (low > high)
		return ;
	pivot_index = partition(arr, low, high);
	quicksort_recursion(arr, low, pivot_index - 1);
	quicksort_recursion(arr, pivot_index + 1, high);
}
