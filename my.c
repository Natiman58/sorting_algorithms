#include "sort.h"
/**
 * cocktail_sort_list - sorts using the cocktail shaker list
 * @list: the list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1; /*1 is true and 0 is false*/
	int start = 0;
	int end = 0;
	int current;
	listint_t *temp;

	if (list == NULL) /*if there is no list do nothing*/
		return;
	temp = *list; /*if there is list temp points to the list*/
	while (temp->next != NULL) /*if there is next node in the list*/
				     /*temp moves to the next node*/
		temp = temp->next, end++;
	temp = *list; /*temp holds the list*/
	while (swapped == 1)
	{
		/*first pass form the beggining ´of the list.*/
		current = start; /*current starts from the first element;0*/
		while (current < end) /*while current element is < the end element*/
					/*forward pass to the end of the list*/
		{
			if (temp->n > temp->next->n) /*if the data of the first node*/
						       /*> than the next node; swap*/
			{
				swap_func(temp, temp->next, list);
				swapped = 1; /*flag is set as swapped*/
			}
			else /*else temp keeps on moving forward*/
				temp = temp->next;
			current++; /*moving forward*/
		}
		/*start second pass from the end element to the left*/
		c = end;
		s = 0; /*reset the swap of the first pass.*/

		while (c > s)
		{
			if (temp->n < temp->prev->n)
			{
				swap(temp->prev, temp, list);
				swapped = 1;
			}
			else
				temp = temp->prev;
			c--;
		}
		start++;
	}
}


/**
 * swap_func - swaps the two nodes
 * @left: left node
 * @right: right node
 * @head: pointer to the head of the list
 */
void swap_func(listint_t *left, listint_t *right, listint_t **head)
{
	listint_t *temp;

	temp = left->prev; /*temp points to the first node*/
	if (temp) /*if there is a prev element temp moves to the next element*/
		temp->next = right; /*set the right node as the next node*/

	/*if there is no prev element temp is the first element*/
	 /*then swap left(1st) and right(2nd) nodes*/
	right->prev = temp;
	left->prev = right;
	left->next = right->next;
	right->next = left;

	if (left->next != NULL)/*if there is another node ater the swaped left*/
				 /*the new left is the prev element*/
				  /* of the immediate nxt node*/
		left->next->prev = left;
	if (right->prev == NULL) /*if there is no element before the swapped right*/
				   /*right becomes the first element pointed by head*/
		*head = right;
	print_list(*head);
}





