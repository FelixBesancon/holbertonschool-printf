#include <stdlib.h>
#include <stdarg.h>

#ifndef MAIN_H
#define MAIN_H

typedef struct specifier
{
	char type;
	void (*print_format)(va_list);
} spec;

int _putchar(char c);
int _printf(const char *format, ...);
void print_percent(va_list args);
void print_char(va_list args);
void print_string(va_list args);

#endif
