#include <stdlib.h>
#include <stdarg.h>

#ifndef MAIN_H
#define MAIN_H

typedef struct specifier
{
	char type;
	int (*print_format)(va_list);
} spec;

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);

#endif
