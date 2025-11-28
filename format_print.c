#include "main.h"

/**
 * print_char - Prints a single character.
 * @args: The character to print.
 *
 * Return: Always 1.
 */
int print_char(va_list args, char *buffer, int *add)
{
	char c = va_arg(args, int);

    print_buffer(buffer, add, c);
	return (1);
}

/**
 * print_string - Prints a string of characters, prints (null)
 * if the string is NULL.
 * @args: The string to print.
 *
 * Return: The length of the string to print.
 */
int print_string(va_list args, char *buffer, int *add)
{
	int count = 0;
	char *s = va_arg(args, char *), *null_string = "(null)";

	if (s == NULL)
	{
		for (; *null_string != '\0'; null_string++, count++)
			print_buffer(buffer, add, *null_string);
	}
	else
	{
		for (; *s != '\0'; s++, count++)
			print_buffer(buffer, add, *s);
	}
	return (count);
}

/**
 * print_percent - Prints a '%' character.
 * @args: The character '%'.
 *
 * Return: Always 1.
 */
int print_percent(va_list args, char *buffer, int *add)
{
	(void)args;
	print_buffer(buffer, add, '%');
	return (1);
}

/**
* print_int_rec - Prints positive numbers recursively.
* @i: The number to print.
*
* Return: the lenght of number to prints
*/
int print_int_rec(int i, char *buffer, int *add)
{
	int count;

	if (i < 10)
	{
		print_buffer(buffer, add, '0' + i);
		return (1);
	}
	count = print_int_rec(i / 10, buffer, add);
	print_buffer(buffer, add, '0' + (i % 10));
	return (count + 1);
}

/**
 * print_int - Prints an integer.
 * @args: The integer to print.
 *
 * Return: The lenght of the integer to print.
 */
int print_int(va_list args, char *buffer, int *add)
{
	int i = va_arg(args, int);
	int count = 0;

	if (i == INT_MIN)
	{
		print_buffer(buffer, add, '-');
		print_buffer(buffer, add, '2');
		count = print_int_rec(147483648, buffer, add);
		return (count + 2);
	}
	if (i < 0)
	{
		print_buffer(buffer, add, '-');
		i = -i;
		count++;
	}
	count += print_int_rec(i, buffer, add);
	return (count);
}
