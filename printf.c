#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: Format string
 * Return: Characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	int buff_ind = 0;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (int k = 0; format[k] != '\0'; k++)
	{
		if (format[k] != '%')
		{
			buffer[buff_ind++] = format[k];
			if (buff_ind == BUFF_SIZE)
			{
				write(1, (const void *)buffer, buff_ind);
				printed_chars += buff_ind;
				buff_ind = 0;
			}
			else
			{
				printed_chars++;
			}
		}
		else
		{
			write(1, (const void *)buffer, buff_ind);
			printed_chars += buff_ind;
			buff_ind = 0;

			k++;
			int flags = get_flags(format, &k);
			int width = get_width(format, &k, args);
			int precision = get_precision(format, &k, args);
			int size = get_size(format, &k);

			int printed = handle_print(format, &k, args, buffer,
					flags, width, precision, size);

			if (printed == -1)
				return (-1);

			printed_chars += printed;
		}
	}

	write(1, (const void *)buffer, buff_ind);
	printed_chars += buff_ind;

	va_end(args);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Buffer array
 * @buff_ind: Index at which to add next character, represents the length
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, (const void *)buffer, *buff_ind);
		*buff_ind = 0;
	}
}
