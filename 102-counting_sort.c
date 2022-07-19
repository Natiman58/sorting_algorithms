#include "sort.h"
/**
 * counting_sort - sorts a list using the counting sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max_num, *count, i, *output, j;

	if (!array || size < 2)
		return;

	/*if there is an array find the max value*/
	max_num = find_max(array, size);

	/*create the output array of same size*/
	output = malloc(sizeof(int) * (int)size);

	/*create an auxiliary array with number of items per key*/
	count = malloc(sizeof(int) * (max_num + 1));

	if (count == NULL || output == NULL)
		return;
	/*determine count of each value of an array; i*/
	for (i = j = 0; i < max_num + 1; i++)
	{
		j += counter(array, size, i);
		count[i] = j;
	}
	print_array(count, max_num + 1);

	for (i = 0; i < (int)size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
	free(output);
	free(count);
}
/**
 * find_max - finds the max number in the array
 * @array: the array to look into
 * @size: size of the array
 * Return: the max value in the array
 */
int find_max(int *array, size_t size)
{
	int i;
	int max_num = 0;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max_num)
			max_num = array[i];
	}
	return (max_num);
}


/**
 * counter - counts the number of times a value is listed
 * @array: the array to look into
 * @size: the size of the array
 * @value: the value to be counted
 * Return: the number of time a value is counted
 */
int counter(int *array, size_t size, int value)
{
	int count = 0;
	int i;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] == value)
			count++;
	}
	return (count);
}
