#include "main.h"

/**
* print_octal_rec - Prints recursively an unsigned int
* converted into octal.
* @o: The unsigned int to convert and print.
*
* Return: The length of the number printed.
*/
unsigned int print_octal_rec(unsigned int o, char *buffer, int *add)
{
	int count;

	if (o < 8)
	{
		print_buffer('0' + o, buffer, add);
		return (1);
	}
	count = print_octal_rec(o / 8, buffer, add);
	print_buffer('0' + (o % 8), buffer, add);
	return (count + 1);
}

/**
* print_octal - Prints an unsigned int converted
* into octal.
* @args: The unsigned int to convert and print.
*
* Return: The length of the number printed.
*/
int print_octal(va_list args, char *buffer, int *add)
{
	unsigned int o = va_arg(args, unsigned int);
	int count = 0;

	count += print_octal_rec(o, buffer, add);
	return (count);
}

/**
* print_hexa_rec - Prints recursively an unsigned int
* converted into hexadecimal.
* @x: The unsigned int to convert and print.
*
* Return: The length of the number printed.
*/
unsigned int print_hexa_rec(unsigned int x, char *buffer, int *add)
{
	int count;

	if (x < 16)
	{
		if (x > 9)
			print_buffer('0' + (x + 39), buffer, add);
		else
			print_buffer('0' + x, buffer, add);
		return (1);
	}
	count = print_hexa_rec(x / 16, buffer, add);
	if ((x % 16) > 9)
		print_buffer('0' + ((x % 16) + 39), buffer, add);
	else
		print_buffer('0' + (x % 16), buffer, add);
	return (count + 1);
}

/**
* print_hexa - Prints an unsigned int converted
* into hexadecimal.
* @args: The unsigned int to convert and print.
*
* Return: The length of the number printed.
*/
int print_hexa(va_list args, char *buffer, int *add)
{
	unsigned int x = va_arg(args, unsigned int);
	int count = 0;

	count += print_hexa_rec(x, buffer, add);
	return (count);
}
