#include "main.h"

/**
 * get_size - Calculates size to cast argument
 * @format: Formatted string in which to print the arguments
 * @k: Current index
 *
 * Return: Size
 */
int get_size(const char *format, int *k)
{
	int curr_k = *k + 1;
	int size = 0;

	if (format[curr_k] == 'l')
		size = S_LONG;
	else if (format[curr_k] == 'h')
		size = S_SHORT;
	else
		return (size);

	*k = curr_k;

	return (size);
}
