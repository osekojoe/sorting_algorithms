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
	
	pre_qsort(array, 0, size - 1, size);
}

int partition(int *a, int lower_bound, int upper_bound)
{
	int pivot, start, end;
	int tmp;

	pivot = a[lower_bound];
	start = lower_bound;
	end = upper_bound;

	while (start < end)
	{
		while (a[start] <= pivot)
		{
			start++;
		}
		while (a[end] > pivot)
		{
			end--;
		}
		if (start < end)
		{
			tmp = a[start];;
			a[start] = a[end];
			a[end] = tmp;
		}
	}
	tmp = a[lower_bound];
	a[lower_bound] = a[end];
	a[end] = tmp;

	return end;
}
void pre_qsort(int *a, int lower_bound, int upper_bound, int size)
{
	int loc;

	if (lower_bound < upper_bound)
	{
		loc = partition(a, lower_bound, upper_bound);
		pre_qsort(a, lower_bound, loc - 1, size);
		pre_qsort(a, loc + 1, upper_bound, size);

		print_array(a, size);
	}
}
