#include "sort.h"
/**
 * merge_sort - lists a sort using merge sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *ptr;

	if (array == NULL || size < 2)
		return;
	/*create an array of integers of size + 1*/
	ptr = malloc(sizeof(int) * (size + 1));
	if (!ptr)
		return;
	split(array, 0, size - 1, ptr);
	free(ptr);
}


/**
 * split - splits the array into left, middle, right subarrays
 * @left: left sub array
 * @right: right sub array
 * @array: the array to be split
 * @temp: temp pointer to the set of integers in the array
 */
void split(int *array, int left, int right, int *temp)
{
	int middle;

	if (left < right)
	{
		middle = ((left - 1) + right) / 2;
		split(array, left, middle, temp);
		split(array, middle + 1, right, temp);
		merge(array, left, middle, right, temp);
	}
}

/**
 * merge - merges the splitted array
 * @array: the merged array
 * @low: the lower sub array
 * @high: the higher sub array
 * @middle: the moddel sub array
 * @temp: temp pointer to the array
 */
void merge(int *array, int low, int middle, int high, int *temp)
{
	int i, j, k, l = 0, r = 0, n, left[4096], right[4096];

	printf("Merging...\n");
	i = low, j = middle + 1, k = l = 0;

	while (i <= middle && j <= high)
	{
		if (array[i] <= array[j])
			temp[k] = left[l] = array[i], k++, i++, l++;
		else
			temp[k] = right[r] = array[j], k++, j++, r++;
	}
	while (i <= middle)
		temp[k] = left[l] = array[i], k++, i++, l++;
	while (j <= high)
		temp[k] = right[r] = array[j], k++, j++, r++;
	printf("[left]: ");
	for (n = 0; n < r; n++)
		(n == 0) ? printf("%d", left[n]) : printf(", %d", left[n]);
	printf("\n[right]: ");
	for (n = 0; n < r; n++)
		(n == 0) ? printf("%d", right[n]) : printf(", %d", right[n]);
	printf("\n[Done]: ");

	for (i = low; i <= high; i++)
	{
		array[i] = temp[i - low], printf("%d", array[i]);
		if (i != high)
			printf(", ");
		else
			printf("\n");
	}
}
