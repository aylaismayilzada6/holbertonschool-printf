#include "main.h"

/**
 * print_char - prints a character
 * @args: argument list
 *
 * Return: number of characters printed
 */
int print_char(va_list args)
{
	char c = (char)va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_string - prints a string
 * @args: argument list
 *
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (!str)
		str = "(null)";

	while (*str)
	{
		write(1, str++, 1);
		count++;
	}
	return (count);
}

/**
 * print_percent - prints a percent sign
 * @args: argument list (unused)
 *
 * Return: number of characters printed
 */
int print_percent(va_list args)
{
	(void)args;
	write(1, "%", 1);
	return (1);
}



/**
 * print_int - prints a signed integer
 * @args: argument list
 *
 * Return: number of characters printed
 */
int print_int(va_list args)
{
    int n = va_arg(args, int);
    char buffer[12]; /* Enough for INT_MIN and '\0' */
    int i = 0, count = 0;
    unsigned int num;

    if (n < 0)
    {
        write(1, "-", 1);
        count++;
        num = -n;
    }
    else
        num = n;

    /* convert number to string in reverse */
    if (num == 0)
    {
        write(1, "0", 1);
        return (1);
    }

    while (num)
    {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    }

    /* print in correct order */
    while (--i >= 0)
    {
        write(1, &buffer[i], 1);
        count++;
    }

    return (count);
}

