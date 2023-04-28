#include "sort.h"

/**
 * identical_element - checks if @array is an array of identical elements
 *
 * @array: input array of integers
 * @size: size of @array
 *
 * Return: 0 if @array is an array of identical elements. Otherwise 1
*/
int identical_element(int *array, size_t size)
{
	int element;
	size_t i;

	element = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] != element)
			return (1);
	}
	return (0);
}

/**
 * swap - swaps the values at two different indices of an array
 *
 * @first: value at first index
 * @second: value at second index
*/
void swap(int *first, int *second)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

/**
 * shell_sort - sorts an array of integers in ascending
 *				order using the Shell sort algorithm,
 *				using the Knuth sequence
 *
 * @array: input array of integers
 * @size: size of @array
*/
void shell_sort(int *array, size_t size)
{
	int i, identical = 1;
	size_t j, interval, gap;

	if (!array || identical == 0)
		return;

	/* generate Knuth sequence */
	interval = 1;
	while (interval <= size / 3)
	{
		interval = interval * 3 + 1;
	}

	for (gap = interval; gap >= 1; (gap = (gap - 1) / 3))
	{
		for (j = gap; j < size; j++)
		{
			for (i = j - gap; i >= 0; i = i - gap)
			{
				if (array[i + gap] > array[i])
					break;
				swap(&array[i + gap], &array[i]);
			}
		}
		print_array(array, size); /* prints array at each interval */
	}
}
