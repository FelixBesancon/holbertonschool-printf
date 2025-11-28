
#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
/**
* struct specifier - the structure combines format
* and a printing function
* @type: stock the characters to check
* @print_format: pointer function handles the
* type of characters
*/
typedef struct specifier
{
	char type;
	int (*print_format)(va_list);
} spec;

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_binary(va_list args);
int print_uint(va_list args);
int print_octal(va_list args);
int print_hexa(va_list args);
int print_HEXA(va_list args);
int print_STRING(va_list args);
int print_pointer(va_list args);
int print_rot13(va_list args);

#endif
