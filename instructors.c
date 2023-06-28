#include "main.h"

/**
 * write_number - Writes a num tobuffer
 * @is_neg: Indicates if num is neg
 * @start_index: Starting index in the buffer
 * @buffer: Buffer array
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters written
 */
int write_number(int is_neg, int start_index, char buffer[],
		int flags, int width, int precision, int size)
{
	int chars_printed = 0;
	int k = start_index;

	(void)buffer;
	(void)flags;
	(void)width;
	(void)precision;
	(void)size;

	if (is_neg)
	{
		write(1, "-", 1);
		chars_printed++;
		k++;
	}

	while (buffer[k] != '\0')
	{
		write(1, &buffer[k], 1);
		chars_printed++;
		k++;
	}

	return (chars_printed);
}
