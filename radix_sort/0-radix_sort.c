#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <sys/types.h>

/**
 * radix_sort - sort the element based on LSD
 * @array: the array to sort
 * @size: size of the array
 */

void radix_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	int max = get_max(array, size);

	for (int exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort(array, size, exp);
		print_array(array, size);
	};
}

/**
 * get_max - get the max value in the array
 * @array: the array to study
 * @size: the size of the array
 * Return: the max value
 */
int get_max(int *array, size_t size)
{
	int max = array[0];

	for (size_t i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - counting sort by current digit
 * @array: the array to sort
 * @size: the size of the array
 * @exp: exponent for each decimal
 */
void counting_sort(int *array, size_t size, int exp)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0};

	for (size_t i = 0; i < size; i++)
	{
		int digit = (array[i] / exp) % 10;

		count[digit]++;
	}

	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (ssize_t i = size - 1; i >= 0; i--)
	{
		int digit = (array[i] / exp) % 10;

		output[count[digit] - 1] = array[i];
		count[digit]--;
	}

	for (size_t i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}
