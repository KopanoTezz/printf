#include "main.h"

/**
 * get_flags - Calculates flags
 * @format: Formatted string in which to print the arguments
 * @k: Current index
 * Return: Flags
 */
int get_flags(const char *format, int *k)
{
	int flags = 0;
	const char FLAGS_CH[] = "-+0# ";
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE};

	int curr_k = *k + 1;

	while (format[curr_k] != '\0')
	{
		int j;

		for (j = 0; FLAGS_CH[j] != '\0'; j++)
		{
			if (format[curr_k] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
		}

		if (FLAGS_CH[j] == '\0')
			break;

		curr_k++;
	}

	*k = curr_k - 1;

	return (flags);
}
