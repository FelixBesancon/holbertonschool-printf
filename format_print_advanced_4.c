#include "main.h"

/**
 * print_rev_rec - Prints recursively a string
 * in reverse.
 * @r: The string to print in reverse.
 * @buffer: The buffer used to store characters before writing to stdout.
 * @add: Pointer to the current number of characters stored in the buffer.
 *
 * Return: The length of the printed string.
 */
int print_rev_rec(char *r, char *buffer, int *add)
{
	int count = 0;

	if (*r == '\0')
		return (0);
	count = print_rev_rec(r + 1, buffer, add);
	print_buffer(*r, buffer, add);
	return (count + 1);
}

/**
 * print_rev - Prints a reversed string,
 * prints (null) if the string is NULL.
 * @args: The string to print in reverse.
 * @buffer: The buffer used to store characters before writing to stdout.
 * @add: Pointer to the current number of characters stored in the buffer.
 *
 * Return: The length of the string to print.
 */
int print_rev(va_list args, char *buffer, int *add)
{
	int count = 0;
	char *r = va_arg(args, char *), *null_string = "(null)";

	if (r == NULL)
	{
		for (; *null_string != '\0'; null_string++, count++)
			print_buffer(*null_string, buffer, add);
	}
	else
		count = print_rev_rec(r, buffer, add);
	return (count);
}

/**
 * print_rot13 - Prints a string of characters using rot13,
 * prints (null) if the string is NULL.
 * @args: The string to print.
 * @buffer: The buffer used to store characters before writing to stdout.
 * @add: Pointer to the current number of characters stored in the buffer.
 *
 * Return: The length of the string to print.
 */
int print_rot13(va_list args, char *buffer, int *add)
{
	int index, count = 0;
	char *R = va_arg(args, char *), *null_string = "(null)";
	char *from = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *to = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	if (R == NULL)
	{
		for (; *null_string != '\0'; null_string++, count++)
			print_buffer(*null_string, buffer, add);
	}
	else
	{
		for (; *R != '\0'; R++, count++)
		{
			index = 0;
			while (from[index] != '\0' && *R != from[index])
				index++;
			if (*R == from[index])
				print_buffer(to[index], buffer, add);
			else
				print_buffer(*R, buffer, add);
		}
	}
	return (count);
}
