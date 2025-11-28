#include "main.h"

/**
 * get_spec_function - Get a function to print an input in the
 * correct format, given a specifier.
 * @sp: The specifier to match with the correct function.
 *
 * Return: A pointer to the correct function, return NULL
 * if no match is found.
 */
int (*get_spec_function(char sp))(va_list, char *buffer, int *add)
{
	int index;
	spec print_table[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_int},
		{'i', print_int},
		{'b', print_binary},
		{'u', print_uint},
		{'o', print_octal},
		{'x', print_hexa},
		{'X', print_HEXA},
		{'S', print_STRING},
		{'p', print_pointer},
		{'r', print_rev},
		{'R', print_rot13},
		{0, NULL},
	};

	for (index = 0; print_table[index].type != 0; index++)
	{
		if (sp == print_table[index].type)
			return (print_table[index].print_format);
	}
	return (NULL);
}

/**
 * _printf - Prints formated output to the standard output.
 * @format: The string to print containing the specifiers.
 *
 * Return: The number of characters printed, return -1 on error.
 */
int _printf(const char *format, ...)
{
	int index, count = 0, add = 0;
	char buffer[1024];
	va_list args;
	int (*get_function)(va_list, char *buffer, int *add);

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (index = 0; format[index] != '\0'; index++)
	{
		if (format[index] != '%')
		{
			print_buffer(format[index], buffer, &add);
			count++;
		}
		else
		{
			if (format[index + 1] == '\0')
			{
				va_end(args);
				return (-1);
			}
			get_function = get_spec_function(format[index + 1]);
			if (get_function != NULL)
				count += get_function(args, buffer, &add), index++;
			else
			{
				print_buffer('%', buffer, &add);
				print_buffer(format[index + 1], buffer, &add);
				count += 2;
				index++;
			}
		}
	}
	write(1, buffer, add);
	va_end(args);
	return (count);
}
