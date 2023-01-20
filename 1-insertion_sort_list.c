#include "sort.h"

/**
* insertion_sort_list - sorts a doubly linked list of integers in
* ascending order using the Insertion sort algorithm
*
* @list: list to be sorted
* Return: None
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *tmp;

	if (!list)
		return;

	ptr = *list;

	while (ptr)
	{
		while (ptr->next && (ptr->n > ptr->next->n))
		{
			tmp = ptr->next;
			ptr->next = tmp->next;
			tmp->prev = ptr->prev;

			if (ptr->prev)
				ptr->prev->next = tmp;

			if (tmp->next)
				tmp->next->prev = ptr;

			ptr->prev = tmp;
			tmp->next = ptr;

			if (tmp->prev)
				ptr = tmp->prev;
			else
				*list = tmp;
			print_list(*list);
		}
		ptr = ptr->next;
	}
}
