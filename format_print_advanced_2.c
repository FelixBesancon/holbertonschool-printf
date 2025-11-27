#include "main.h"

/**
* print_octal_rec - Prints recursively an unsigned int
* converted into octal.
* @o: The unsigned int to convert and print.
*
* Return: The length of the number printed.
*/
unsigned int print_octal_rec(unsigned int o)
{
	int count;

	if (o < 8)
	{
		_putchar('0' + o);
		return (1);
	}
	count = print_octal_rec(o / 8);
	_putchar('0' + (o % 8));
	return (count + 1);
}

/**
* print_octal - Prints an unsigned int converted
* into octal.
* @args: The unsigned int to convert and print.
*
* Return: The length of the number printed.
*/
int print_octal(va_list args)
{
	unsigned int o = va_arg(args, unsigned int);
	int count = 0;

	count += print_octal_rec(o);
	return (count);
}

/**
* print_hexa_rec - Prints recursively an unsigned int
* converted into hexadecimal.
* @x: The unsigned int to convert and print.
*
* Return: The length of the number printed.
*/
unsigned int print_hexa_rec(unsigned int x)
{
	int count;

	if (x < 16)
	{
		if (x > 9)
			_putchar('0' + (x + 39));
		else
			_putchar('0' + x);
		return (1);
	}
	count = print_hexa_rec(x / 16);
	if ((x % 16) > 9)
		_putchar('0' + ((x % 16) + 39));
	else
		_putchar('0' + (x % 16));
	return (count + 1);
}

/**
* print_hexa - Prints an unsigned int converted
* into hexadecimal.
* @args: The unsigned int to convert and print.
*
* Return: The length of the number printed.
*/
int print_hexa(va_list args)
{
	unsigned int x = va_arg(args, unsigned int);
	int count = 0;

	count += print_hexa_rec(x);
	return (count);
}
