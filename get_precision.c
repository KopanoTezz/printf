#include "main.h"

/**
 * get_precision - Calculates precision for printing
 * @format: Formatted string in which to print the arguments
 * @k: Current index
 * @list: List of arguments
 *
 * Return: Precision
 */
int get_precision(const char *format, int *k, va_list list)
{
	int curr_k = *k + 1;
	int precision = -1;

	if (format[curr_k] != '.')
		return (precision);

	precision = 0;
	curr_k++;

	while (is_digit(format[curr_k]))
	{
		precision = precision * 10 + (format[curr_k] - '0');
		curr_k++;
	}

	if (format[curr_k] == '*')
	{
		curr_k++;
		precision = va_arg(list, int);
	}

	*k = curr_k - 1;

	return (precision);
}
