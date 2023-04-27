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

/* Auxiliary function for the quick_sort function */
void _qsort(int *array, int low, int high, int size);

/**
 * quick_sort - function that sorts an array
 *				of integers in ascending order using the
 *				quick sort algorithm.
 *				It implements the Lomuto partition scheme.
 *
 * @array: input arrray
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	/* Call the auxiliary function to sort the array */
	_qsort(array, 0, size - 1, size);
}

/**
 * _qsort - auxiliar function for the
 *			quick_sort function
 *
 * @array: input arrray
 * @low: index for the first element
 * @high: index for the last element
 * @size: size of the array
 */
void _qsort(int *array, int low, int high, int size)
{
	int pivot, wall, i;

	/* If there are at least two elements to sort */
	if (low < high)
	{
		/* Choose the last element as the pivot */
		pivot = high;
		wall = low;
		/* Partition the array into two subarrays */
		for (i = low; i < high; i++)
		{
			if (array[i] < array[pivot])
			{
				/* Swap the current element with the first */
				/* element to the right of the wall */
				if (i != wall)
				{
					swap(&array[i], &array[wall]);
					print_array(array, size);
				}
				/* Move the wall one position to the right */
				wall++;
			}
		}
		/* Swap the pivot with the element at the wall position */
		if (wall != pivot && array[wall] != array[pivot])
		{
			swap(&array[wall], &array[pivot]);
			print_array(array, size);
		}
		/* Sort the subarrays to the left and right of the pivot recursively */
		_qsort(array, low, wall - 1, size);
		_qsort(array, wall + 1, high, size);
	}
}
