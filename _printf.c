#include "main.h"
/**
 * _printf - Prints formated output to the standard output.
 * @format: The string to print containing the specifiers.
 *
 * Return: The numbers of characters printed, return -1 on error.
 */
int _printf(const char *format, ...)
{
	int index, index_2, count = 0, found;
	spec print_to_what[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'d', print_int}, {'i', print_int}, {'b', print_binary}, {'u', print_uint},
		{'o', print_octal}, {'x', print_hexa}, {'X', print_HEXA}, {'S', print_STRING},
		{'p', print_pointer}, {0, NULL},
	};
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (index = 0; format[index] != '\0'; index++)
	{
		found = 0;
		if (format[index] != '%')
		{ _putchar(format[index]), count++; }
		else
		{
			for (index_2 = 0; found != 1 && print_to_what[index_2].type != 0; index_2++)
			{
				if (format[index + 1] == print_to_what[index_2].type)
				{
					count += print_to_what[index_2].print_format(args);
					found = 1, index++;
				}
			}
			if (found == 0)
			{
				if (format[index + 1] == '\0')
				{
					va_end(args);
					return (-1);
				}
				_putchar(format[index]), count++;
			}
		}
	}
	va_end(args);
	return (count);
}
