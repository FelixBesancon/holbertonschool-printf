#include "main.h"

/**
* print_binary_rec - Prints recursively an unsigned int
* converted into binary.
* @b: The unsigned int to convert and print.
*
* Return: The number of '1' and '0' printed.
*/
unsigned int print_binary_rec(unsigned int b)
{
	int count = 0;

	if (b == 0)
		return (0);
	count = print_binary_rec(b / 2);
	_putchar('0' + (b % 2));
	return (count + 1);
}

/**
* print_binary - Prints an unsigned int converted
* into binary.
* @args: The unsigned int to convert and print.
*
* Return: The number of '1' and '0' printed.
*/
int print_binary(va_list args)
{
	unsigned int b = va_arg(args, unsigned int);

	if (b == 0)
	{
		_putchar ('0');
		return (1);
	}
	return (print_binary_rec(b));
}

/**
* print_uint_rec - Prints positive numbers recursively.
* @u: The number to print.
*
* Return: the lenght of number to prints
*/
int print_uint_rec(unsigned int u)
{
	int count;

	if (u < 10)
	{
		_putchar('0' + u);
		return (1);
	}
	count = print_uint_rec(u / 10);
	_putchar('0' + (u % 10));
	return (count + 1);
}

/**
 * print_uint - Prints an integer.
 * @args: The unsigned integer to print.
 *
 * Return: The lenght of the unsigned integer
 * to print.
 */
int print_uint(va_list args)
{
	int u = va_arg(args, unsigned int);
	int count = 0;

	count += print_uint_rec(u);
	return (count);
}
