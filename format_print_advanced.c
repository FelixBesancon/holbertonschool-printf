#include "main.h"

/**
* print_binary_rec - Prints recursively an unsigned int
* converted into binary.
* @b: The unsigned int to convert and print.
* @buffer: The buffer used to store characters before writing to stdout.
* @add: Pointer to the current number of characters stored in the buffer.
*
* Return: The number of '1' and '0' printed.
*/
int print_binary_rec(unsigned int b, char *buffer, int *add)
{
	int count = 0;

	if (b == 0)
		return (0);
	count = print_binary_rec(b / 2, buffer, add);
	print_buffer('0' + (b % 2), buffer, add);
	return (count + 1);
}

/**
* print_binary - Prints an unsigned int converted
* into binary.
* @args: The unsigned int to convert and print.
* @buffer: The buffer used to store characters before writing to stdout.
* @add: Pointer to the current number of characters stored in the buffer.
*
* Return: The number of '1' and '0' printed.
*/
int print_binary(va_list args, char *buffer, int *add)
{
	unsigned int b = va_arg(args, unsigned int);

	if (b == 0)
	{
		print_buffer('0', buffer, add);
		return (1);
	}
	return (print_binary_rec(b, buffer, add));
}

/**
* print_uint_rec - Prints positive numbers recursively.
* @u: The number to print.
* @buffer: The buffer used to store characters before writing to stdout.
* @add: Pointer to the current number of characters stored in the buffer.
*
* Return: the lenght of number to prints
*/
int print_uint_rec(unsigned int u, char *buffer, int *add)
{
	int count = 0;

	if (u < 10)
	{
		print_buffer('0' + u, buffer, add);
		return (1);
	}
	count = print_uint_rec(u / 10, buffer, add);
	print_buffer('0' + (u % 10), buffer, add);
	return (count + 1);
}

/**
 * print_uint - Prints an integer.
 * @args: The unsigned integer to print.
 * @buffer: The buffer used to store characters before writing to stdout.
 * @add: Pointer to the current number of characters stored in the buffer.
 *
 * Return: The lenght of the unsigned integer
 * to print.
 */
int print_uint(va_list args, char *buffer, int *add)
{
	unsigned int u = va_arg(args, unsigned int);

	return (print_uint_rec(u, buffer, add));
}
