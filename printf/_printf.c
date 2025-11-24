#include "main.h"
#include <stdlib.h>
/**
 * _printf - Prints formated output to the standard output.
 * @format: The string to print containing the specifiers.
 *
 * Return: The numbers of characters printed.
 */
int _printf(const char *format, ...)
{
	int i;

	for (i = 0; format[i] != '\0'; i++)
	{
		_putchar(format[i]);
	}
	return (i);
}
