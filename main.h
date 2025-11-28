
#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>
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
	int (*print_format)(va_list, char *, int *);
} spec;

int _putchar(char c);
int print_buffer(char c, char *buffer, int *add);
int _printf(const char *format, ...);
int print_char(va_list args, char *buffer, int *add);
int print_string(va_list args, char *buffer, int *add);
int print_percent(va_list args, char *buffer, int *add);
int print_int(va_list args, char *buffer, int *add);
int print_binary(va_list args, char *buffer, int *add);
int print_uint(va_list args, char *buffer, int *add);
int print_octal(va_list args, char *buffer, int *add);
int print_hexa(va_list args, char *buffer, int *add);
int print_HEXA(va_list args, char *buffer, int *add);
int print_STRING(va_list args, char *buffer, int *add);
#endif
