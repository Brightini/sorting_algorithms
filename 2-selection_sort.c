#include "sort.h"

/**
 * swap - swaps the values at two different indices of an array
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
 * selection_sort - sorts an array of integers in
 *					ascending order using the Selection sort
 *					algorithm
 *
 * @array: input array of integers
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	/* loop to parse the array */
	for (i = 0; i < size; i++)
	{
		min = i;
		/* loop to swap */
		for (j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
				min = j;
		}

		if (i != min)
		{
			swap(&array[i], &array[min]);
			print_array(array, size); /* prints array for every successful swap */
		}
	}
}
