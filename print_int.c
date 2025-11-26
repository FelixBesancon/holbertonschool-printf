#include "main.h"
/**
* print_int_rec - Prints positive numbers
* @i: Number to prints
*
* Return: the size of numbers to prints
*/
int print_int_rec(int i)
{
	int count;

	if (i < 10)
	{
		_putchar('0' + i);
		return (1);
	}
	count = print_int_rec(i / 10);
	_putchar('0' + (i % 10));

	return (count + 1);
}
/**
 * print_int - Prints an integer.
 * @args: The integer to print.
 *
 * Return: The lenght of the integer to print.
 */
int print_int(va_list args)
{
	int i = va_arg(args, int);
	int count = 0;

	if (i == INT_MIN)
	{
		_putchar('-');
		_putchar('2');
		count = print_int_rec(147483648);
		return (count + 2);
	}

	if (i < 0)
	{
		_putchar('-');
		i = -i;
		count = print_int_rec(i);
		return (count + 1);
	}
	else
	{
		count = print_int_rec(i);
		return (count);
	}
}
