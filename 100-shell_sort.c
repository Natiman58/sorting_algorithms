#include "sort.h"
/**
 * shell_sort - sorts using the Knuth Sequence
 * @array: the array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, k;
	size_t interval = 1;
	int temp;

	if (!array) /*if no array or arrray is empty do nothing*/
		return;
	while (interval < size) /*if interval is less than the array,*/
				  /*use knuth increment*/
		interval = (3 * interval) + 1;
	if (interval >= size) /*if interval > array size;*/
				/*make the interval multiple of 3*/
		interval = (interval - 1) / 3;
	while (interval > 0)
	{
		for (i = interval; i < size; i++) /*iterate through the list*/
						    /*at every i'th interval*/
		{
			temp = array[i]; /*temp holds the first element*/

			/*start from far apart elements & progressively reduce gap*/
			for (k = i; (k > interval - 1) &&
					(temp < array[k - interval]); k -= interval)
			{
				array[k] = array[k - interval]; /*switch the 2 far apart elements.*/
			}
			array[k] = temp;
		}
		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}
