#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, j, count = 0, printed;
	va_list args;
	spec_t specs[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{NULL, NULL}
	};

	if (!format)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count++;
		}
		else
		{
			i++;
			j = 0;
			printed = 0;

			while (specs[j].valid)
			{
				if (format[i] == specs[j].valid[0])
				{
					count += specs[j].f(args);
					printed = 1;
					break;
				}
				j++;
			}

			if (!printed)
			{
				write(1, "%", 1);
				write(1, &format[i], 1);
				count += 2;
			}
		}
		i++;
	}

	va_end(args);
	return (count);
}

