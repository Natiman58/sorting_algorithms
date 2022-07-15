#include "sort.h"
/**
 *insertion_sort_list - sorts a linked list using
 *insertion sort algorithm
 *@list: the list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *ptr;

	if (!list || !*list)
		return;
	current = (*list)->next;

	while (current)
	{
		ptr = current->next;
		while (current->prev && current->n < current->prev->n)
		{
			current->prev->next = current->next;
			if (current->next)
			current->next->prev = current->prev;
			current->next = current->prev;
			current->prev = current->prev->prev;

			if (current->prev)
				current->prev->next = current;

			current->next->prev = current;
			if (!current->prev)
				*list = current;

			print_list(*list);
		}
		current = ptr;
	}
}
