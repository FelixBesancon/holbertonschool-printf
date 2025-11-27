#include "main.h"

/**
* print_HEXA_rec - Prints recursively an unsigned int
* converted into capital hexadecimal.
* @X: The unsigned int to convert and print.
*
* Return: The length of the number printed.
*/
unsigned int print_HEXA_rec(unsigned int X)
{
	int count;

	if (X < 16)
	{
		if (X > 9)
			_putchar('0' + (X + 7));
		else
			_putchar('0' + X);
		return (1);
	}
	count = print_HEXA_rec(X / 16);
	if ((X % 16) > 9)
		_putchar('0' + ((X % 16) + 7));
	else
		_putchar('0' + (X % 16));
	return (count + 1);
}

/**
* print_HEXA - Prints an unsigned int converted
* into capital hexadecimal.
* @args: The unsigned int to convert and print.
*
* Return: The length of the number printed.
*/
int print_HEXA(va_list args)
{
	unsigned int X = va_arg(args, unsigned int);
	int count = 0;

	count += print_HEXA_rec(X);
	return (count);
}
