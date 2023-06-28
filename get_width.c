#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments
 * @k: Current index in the format string
 * @list: List of arguments
 *
 * Return: Width
 */
int get_width(const char *format, int *k, va_list list)
{
	int curr_k = *k + 1;
	int width = 0;

	while (is_digit(format[curr_k]))
	{
		width = width * 10 + (format[curr_k] - '0');
		curr_k++;
	}

	if (format[curr_k] == '*')
	{
		curr_k++;
		width = va_arg(list, int);
	}

	*k = curr_k - 1;

	return (width);
}
