#include "main.h"


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
