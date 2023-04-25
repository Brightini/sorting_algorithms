#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 *
 * @array: an array of integers
 * @size: size of array @array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp;

	/* first loop to iterate through the entire array */
	for (i = 0; i < size - 1; i++)
	{
		/* second loop for swapping */
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j]; /* stores value temporary for swap */
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size); /* prints array for every swap */
			}
		}
	}
}
