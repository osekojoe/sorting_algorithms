#include "sort.h"

/**
* selection_sort - sorts an array of integers in ascending order
*  using the Selection sort algorithm
*
* @array: array to be sorted
* @size: size of array
* Return: None
*/
void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
