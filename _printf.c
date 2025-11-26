#include "main.h"
/**
 * _printf - Prints formated output to the standard output.
 * @format: The string to print containing the specifiers.
 *
 * Return: The numbers of characters printed.
 */
int _printf(const char *format, ...)
{
	int i, j, count = 0, found = 0;
	spec print_to_what[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_int},
		{'i', print_int},
		{0, NULL},
	};
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		found = 0;
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else
		{
			if (format[i + 1] == '%')
			{
				found = 1;
				_putchar('%');
				i++;
				count++;
			}
			for (j = 0; found != 1 && print_to_what[j].type != 0; j++)
			{
				if (format[i + 1] == print_to_what[j].type)
				{
					found = 1;
					count += print_to_what[j].print_format(args);
					i++;
				}
			}
		}
	}
	va_end(args);
	return (count);
}
