#include "main.h"

/**
 * print_char - Prints a char
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	(void)buffer;
	(void)flags;
	(void)width;
	(void)precision;
	(void)size;

	return write(1, &c, 1);
}
/**
 * print_binary - Prints unsigned num
 * @types: List of args
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Nums of charcters printed.
 */
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int a[32];
	unsigned int n, f, k, sum;
	int count;

	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	UNUSED(buffer);
	UNUSED(flags);

	n = va_arg(types, unsigned int);
	f = 2147483648; /* (2 ^ 31) */
	a[0] = n / f;
	for (k = 1; k < 32; k++)
	{
		f /= 2;
		a[k] = (n / f) % 2;
	}
	for (k = 0, sum = 0, count = 0; k < 32; k++)
	{
		sum += a[k];
		if (sum || k == 31)
		{
			char z = '0' + a[k];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
/**
 * print_percent - Prints a percent sign
 * @types: List of arguments (unused)
 * Return: Number of characters printed
 */
int print_percent(va_list types)
{
	(void)types;

	return write(1, "%%", 1);
}
/**
 * print_string - Prints a string
 * @types: List a of arguments
 * Return: Number of characters printed
 */
int print_string(va_list types)
{
	int length = 0;
	char *str = va_arg(types, char *);

	if (str == NULL)
		str = "(null)";

	while (str[length] != '\0')
		length++;

	return write(1, str, length);
}
/**
 * print_int - Print int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numb of characters printed
 */
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int k = BUFF_SIZE - 2;
	int is_neg = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[k--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_neg = 1;
	}

	while (num > 0)
	{
		buffer[k--] = (num % 10) + '0';
		num /= 10;
	}

	k++;

	return (write_number(is_neg, k, buffer, flags, width, precision, size));
}
