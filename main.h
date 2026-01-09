#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct specifier - Struct to match specifier with print function
 * @valid: The specifier (c, s, %)
 * @f: The function pointer
 */
typedef struct specifier
{
	char *valid;
	int (*f)(va_list);
} spec_t;

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);

#endif
