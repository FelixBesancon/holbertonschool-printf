#include "main.h"

typedef struct specifier
{
	char type;
	void (*print_format)(va_list);
} spec;
/**
 * _printf - Prints formated output to the standard output.
 * @format: The string to print containing the specifiers.
 *
 * Return: The numbers of characters printed.
 */
int _printf(const char *format, ...)
{
	int i, j;
	char sp;
	spec print_to_what[] = {
		{'c', print_char},
		{0, NULL},
	};
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
			_putchar(format[i]);
		else
		{
			sp = format[i + 1];
			for (j = 0; print_to_what[j].type != 0; j++)
			{
				if (sp == print_to_what[j].type)
				{
					print_to_what[j].print_format(args);
					i++;
				}
			}
		}
	}
	va_end(args);
	return (i);
}
