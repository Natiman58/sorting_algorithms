#include "sort.h"

/**
* swap - Swaps nodes
* @left: left node
* @right: right node
* @head: pointer to the head of the first element
*/

void swap(listint_t *left, listint_t *right, listint_t **head)
{
	listint_t *temp; /*temp points to the list struct*/

	temp = left->prev; /*temp points to the first element*/
	if (temp) /*if temp is the prev element; right is the next*/
		temp->next = right;
	right->prev = temp; /*if there is no left element; temp is the left*/
	left->prev = right;
	left->next = right->next;
	right->next = left;
	if (left->next != NULL)
		left->next->prev = left;
	if (right->prev == NULL)
		*head = right;
	print_list(*head);
}

/**
* cocktail_sort_list - sorts a list using cocktail sort
* @list: the list to be sorted.
*/

void cocktail_sort_list(listint_t **list)
{
	listint_t *temp;
	int flag = 1; /*1 if swapped and 0 if not*/
	int start = 0, end = 0, current;

	if (list == NULL)
		return;
	temp = *list;
	while (temp->next != NULL)
		temp = temp->next, end++;
	temp = *list;
	while (flag == 1)
	{
		/*start first pass from the left to right*/
		current = start;
		while (current < end)
		{
			if (temp->n > temp->next->n)
			{
				swap(temp, temp->next, list);
				flag = 1;
			}
			else
				temp = temp->next;
			current++;
		}
		/*start the second pass from the right; end and reset flag*/
		current = end, flag = 0;
		while (current > start)
		{
			if (temp->n < temp->prev->n)
			{
				swap(temp->prev, temp, list);
				flag = 1;
			}
			else
				temp = temp->prev;
			current--;
		}
		start++; /*start again form the 2nd element in the left*/
	}
}
