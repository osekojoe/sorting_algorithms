#include "sort.h"

/**
* shell_sort - sorts an array  * of integers in ascending order using the
* Shell sort algorithm
*
* @array: array
* @size: size
* Return: None
*/
void shell_sort(int *array, size_t size)
{
	size_t n = 1;

	while (n < size)
		n = (n * 3) + 1;
	while ((n = (n - 1) / 3) > 0)
		_ssort(array, size, n);
}

/**
* _ssort - helper function for shell_sort function
* @a: arrray
* @size: size array
* @n: interval
* Return: None
*/
void _ssort(int *a, int size, int n)
{
	int i, j, tmp;

	for (i = 0; (i + n) < size; i++)
	{
		for (j = i + n; (j - n) >= 0; j = j - n)
		{
			if (a[j] < a[j - n])
			{
				tmp = a[j];
				a[j] = a[j - n];
				a[j - n] = tmp;
			}
		}
	}
	print_array(a, size);
}
