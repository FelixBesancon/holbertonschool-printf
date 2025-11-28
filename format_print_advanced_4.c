#include "main.h"

/**
 * print_rev_rec - Prints recursively a string
 * in reverse.
 * @r: The string to print in reverse.
 *
 * Return: The length of the printed string.
 */
int print_rev_rec(char *r)
{
	int count = 0;

	if (*r == '\0')
		return (0);
	count = print_rev_rec(r + 1);
	_putchar(*r);
	return (count + 1);
}

/**
 * print_rev - Prints a reversed string,
 * prints (null) if the string is NULL.
 * @args: The string to print in reverse.
 *
 * Return: The length of the string to print.
 */
int print_rev(va_list args)
{
	int count = 0;
	char *r = va_arg(args, char *), *null_string = "(null)";

	if (r == NULL)
	{
		for (; *null_string != '\0'; null_string++, count++)
			_putchar(*null_string);
	}
	else
		count = print_rev_rec(r);
	return (count);
}

/**
 * print_rot13 - Prints a string of characters using rot13,
 * prints (null) if the string is NULL.
 * @args: The string to print.
 *
 * Return: The length of the string to print.
 */
int print_rot13(va_list args)
{
	int index, count = 0;
	char *R = va_arg(args, char *), *null_string = "(null)";
	char *from = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *to = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	if (R == NULL)
	{
		for (; *null_string != '\0'; null_string++, count++)
			_putchar(*null_string);
	}
	else
	{
		for (; *R != '\0'; R++, count++)
		{
			index = 0;
			while (from[index] != '\0' && *R != from[index])
				index++;
			if (*R == from[index])
				_putchar(to[index]);
			else
				_putchar(*R);
		}
	}
	return (count);
}
