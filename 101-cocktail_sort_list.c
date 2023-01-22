#include "sort.h"

/**
* swap_list - swap list elements
*
* @ptr1: first pointer
* @ptr2: second pointer
* @n: 0 for increase, 1 for decrease
* Return: None
*/
void swap_list(listint_t **ptr1, listint_t **ptr2, int n)
{
	listint_t *aux, *tmp;

	aux = *ptr1;
	tmp = *ptr2;

	aux->next = tmp->next;
	tmp->prev = aux->prev;

	if (tmp->next)
		tmp->next->prev = aux;

	if (aux->prev)
		aux->prev->next = tmp;

	aux->prev = tmp;
	tmp->next = aux;

	if (n == 0)
		*ptr1 = tmp;
	else
		*ptr2 = aux;
}

/**
 * increase_sort - move the bigger numbers to the end
 *
 * @ptr: pointer to the bigger number
 * @limit: limit of the list
 * @list: list of integers
 * Return: None
 */
void increase_sort(listint_t **ptr, listint_t **limit, listint_t **list)
{
	listint_t *aux;

	aux = *ptr;

	while (aux != *limit && aux->next != *limit)
	{
		if (aux->n > aux->next->n)
		{
			swap_list(&aux, &(aux->next), 0);
			if (aux->prev == NULL)
				*list = aux;
			print_list(*list);
		}
		aux = aux->next;
	}

	*limit = aux;
	*ptr = aux;
}

/**
 * decrease_sort - moves the smaller numbers to the start
 *
 * @ptr: pointer to the smaller number
 * @limit: limit of the list
 * @list: list of integers
 * Return: None
 */
void decrease_sort(listint_t **ptr, listint_t **limit, listint_t **list)
{
	listint_t *aux;

	aux = *ptr;

	while (aux != *limit && aux->prev != *limit)
	{
		if (aux->n < aux->prev->n)
		{
			swap_list(&(aux->prev), &aux, 1);
			if (aux->prev->prev == NULL)
				*list = aux->prev;
			print_list(*list);
		}
		aux = aux->prev;
	}

	*limit = aux;
	*ptr = aux;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in
 *  ascending order using the Cocktail shaker sort algorithm
 *
 * @list: head of the linked list
 * Return: None
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *limit1, *limit2, *ptr;

	if (list == NULL || *list == NULL)
		return;

	limit1 = limit2 = NULL;
	ptr = *list;

	do {
		increase_sort(&ptr, &limit1, list);
		decrease_sort(&ptr, &limit2, list);
	} while (limit1 != limit2);
}
