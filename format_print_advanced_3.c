#include "main.h"

/**
* print_HEXA_rec - Prints recursively an unsigned int
* converted into capital hexadecimal.
* @X: The unsigned int to convert and print.
*
* Return: The length of the number printed.
*/
unsigned int print_HEXA_rec(unsigned int X, char *buffer, int *add)
{
	int count;

	if (X < 16)
	{
		if (X > 9)
			print_buffer('0' + (X + 7), buffer, add);
		else
			print_buffer('0' + X, buffer, add);
		return (1);
	}
	count = print_HEXA_rec(X / 16, buffer, add);
	if ((X % 16) > 9)
		print_buffer('0' + ((X % 16) + 7), buffer, add);
	else
		print_buffer('0' + (X % 16), buffer, add);
	return (count + 1);
}

/**
* print_HEXA - Prints an unsigned int converted
* into capital hexadecimal.
* @args: The unsigned int to convert and print.
*
* Return: The length of the number printed.
*/
int print_HEXA(va_list args, char *buffer, int *add)
{
	unsigned int X = va_arg(args, unsigned int);
	int count = 0;

	count += print_HEXA_rec(X, buffer, add);
	return (count);
}

/**
 * print_STRING - Prints a string of characters, prints (null)
 * if the string is NULL, prints '\x' followed by the ASCII code
 * value of each non printable character.
 * @args: The string to print.
 *
 * Return: The length of the string to print.
 */
int print_STRING(va_list args, char *buffer, int *add)
{
	int count = 0;
	unsigned int char_S;
	char *S = va_arg(args, char *), *null_STRING = "(null)";

	if (S == NULL)
	{
		for (; *null_STRING != '\0'; null_STRING++, count++)
			print_buffer(*null_STRING, buffer, add);
	}
	else
	{
		for (; *S != '\0'; S++, count++)
			if (*S > 31 && *S < 127)
				print_buffer(*S, buffer, add);
			else
			{
				char_S = *S;
				print_buffer('\\', buffer, add), print_buffer('x', buffer, add);
				if (char_S < 16)
					{ print_buffer('0', buffer, add), count++; }
				count += 1 + print_HEXA_rec(char_S, buffer, add);
			}
	}
	return (count);
}
