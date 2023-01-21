#include "sort.h"

/**
* quick_sort - sorts an array of integers in ascending order
* using the Quick sort algorithm
*
* @array: array to be sorted
* @size: size of array
* Return: None
*/
void quick_sort(int *array, size_t size)
{
	_qsort(array, 0, size - 1, size);
}

/**
* swap - swap elements
* @a: first element
* @b: second element
* Return: None
*/
void swap(int a, int b)
{
	int tmp;

	tmp = a;
	a = b;
	b = tmp;
}

/**
* _qsort - partition array along the pivot
*
* @a: array
* @lower_bound: lower bound
* @upper_bound: upper bound
* @size: size of array
* Return: None
*/
void _qsort(int *a, int lower_bound, int upper_bound, int size)
{
	int i, pivot, w, tmp;

	if (lower_bound < upper_bound)
	{
		w = lower_bound;
		pivot = upper_bound;
		for (i = lower_bound; i < upper_bound; i++)
		{
			if (a[i] < a[pivot])
			{
				if (i != w)
				{
					/* swap(a[i], a[w]); */
					tmp = a[i];
					a[i] = a[w];
					a[w] = tmp;
					print_array(a, size);
				}
				w++;
			}
		}
		if (w != pivot && a[w] != a[pivot])
		{
			/* swap(a[w], a[pivot]); */
			tmp = a[w];
			a[w] = a[pivot];
			a[pivot] = tmp;
			print_array(a, size);
		}
		_qsort(a, lower_bound, w - 1, size);
		_qsort(a, w + 1, upper_bound, size);
	}
}
