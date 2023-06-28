#include "main.h"

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

	return (write(1, str, length));
}
/**
 * print_percent - Prints a percent sign
 * @types: List of arguments (unused)
 * Return: Number of characters printed
 */
int print_percent(va_list types)
{
	(void)types;

	return (write(1, "%%", 1));
}
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

	return (write(1, &c, 1));
}
/**
 * print_int - Print int
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	(void)flags;
	(void)width;
	(void)precision;
	(void)size;

	int i = BUFF_SIZE - 1;
	int is_negative = 0;
	long int n = va_arg(types, long int);

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[i + 1] = '\0';

	if (n < 0)
	{
		n = -n;
		is_negative = 1;
	}

	while (n > 0)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}

	int chars_printed = 0;

	while (buffer[i + 1] != '\0')
	{
		write(1, &buffer[i + 1], 1);
		chars_printed++;
		i++;
	}

	return (chars_printed);
}
/**
 * print_binary - Prints unsigned number in binary format
 * @types: List of arguments
 * @buffer: Buffer array
 * @flags: Calc active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numb of characters printed
 */
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int n = va_arg(types, unsigned int);
	unsigned int nmbits = 0;
	unsigned int num = n;

	int count = 0;

	(void)buffer;
	(void)flags;
	(void)width;
	(void)precision;
	(void)size;

	while (num > 0)
	{
		num >>= 1;
		nmbits++;
	}

	if (nmbits == 0)
		nmbits = 1;

	for (unsigned int k = 1 << (nmbits - 1); k != 0; k >>= 1)
	{
		char digit = (n & k) ? '1' : '0';

		if (write(1, &digit, 1) == -1)
			return (-1);
		count++;
	}

	return (count);
}
