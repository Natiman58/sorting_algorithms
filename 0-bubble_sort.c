#include "sort.h"
/**
 * bubble_sort - Sorts an array in accordance to bubble sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int i, j, temp;
	int ar_size = size;

	if (array == NULL || ar_size < 2)
		return;
	for (i = 0; i < ar_size - 1; i++)
	{
		for (j = 0; j < ar_size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{	temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}

		}
	}
}
