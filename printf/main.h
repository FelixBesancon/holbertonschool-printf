#include <stdlib.h>
#include <stdarg.h>

#ifndef MAIN_H
#define MAIN_H

typedef struct specifier
{
	char type;
	unsigned int (*print_format)(va_list);
} spec;

int _putchar(char c);
unsigned int _printf(const char *format, ...);
unsigned int print_char(va_list args);
unsigned int print_string(va_list args);
unsigned int print_int(va_list args);

#endif
