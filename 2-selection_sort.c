#include "sort.h"
/**
 * selection_sort - uses the selection sort algorithm to sort the list
 * @array: the array to be sorted
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	int current_min = 0;
	int true_min = 0;
	int flag = 0; /*Initially true min is not set*/
	size_t i, j;

	for (i = 0; i < size; i++) /* iterate through the list */
	{
		flag = 0;

		/*set the first element as current min*/
		current_min = array[i];

		for (j = i + 1; j < size; j++) /*iterate through the rest of the list*/
		{
			if (array[j] < current_min) /*if nxt element is < current min*/
			{
				current_min = array[j]; /*current_min becomes the smallest*/
				true_min = j; /*store the index of true min(j) in true_min*/
				flag = 1; /*true minimum is found*/
			}
		}
		if (flag == 1) /*if true minimum is found; swap with current min*/
		{
			array[true_min] = array[i];
			array[i] = current_min;
			print_array(array, size);
		}
	}
}
