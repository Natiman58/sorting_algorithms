#include "sort.h"

/**
 * partition - creates partitioned list using the Lomuto partition scheme
 * @array: the array to be partitioned
 * @lo: the lowest element in the array
 * @hi: highest element in the array
 * @size: size of the array
 * Return: the pivot index
 */

size_t partition(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t i, j;
	int swap, pivot;

	pivot = array[hi]; /*choose the last element as pivot*/
	i = lo - 1; /*temporary pivot index; i*/

	for (j = lo; j < hi; j++)
	{
		if (array[j] <= pivot) /*if the current elem is <= to pivot*/
		{
			i++; /*move the temporary pivot index forward. */

			/*if the indexs are different swap the current element with pivot*/
			if (i != j)
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
				print_array(array, size);
			}
		}
	}

	/*move the pivot element to the correct position;*/
	/* b/n smaller and larger elements.*/
	if (array[hi] < array[i + 1])
	{
		swap = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = swap;
		print_array(array, size);
	}
	return (i + 1); /*the pivot index*/
}

/**
 * part_sort - sorts the partitioned list
 * @array: the partitioned array
 * @lo: the lowest element in the list
 * @hi: the highest element in the list
 * @size: size of the array
 */

void part_sort(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t pivot;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi, size);
		part_sort(array, lo, pivot - 1, size);
		part_sort(array, pivot + 1, hi, size);
	}
}

/**
 * quick_sort - sorts a list using quick sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	part_sort(array, 0, size - 1, size);
}
