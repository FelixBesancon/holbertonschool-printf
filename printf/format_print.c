#include "main.h"
/** print_char - Prints a single character.
 * @args: The character to print.
 *
 * Return: Void.
 */
unsigned int print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1);
}
/**
 * print_string - Prints a string of characters.
 * @args: The string to print.
 *
 * Return: Void.
 */
unsigned int print_string(va_list args)
{
	int i;
	unsigned int count = 0;
	char *s = va_arg(args, char *);

	if (s != NULL)
	{
		for (i = 0; s[i] != '\0'; i++, count++)
			_putchar(s[i]);
	}
	return (count);
}
/** print_int - Prints an integer.
 * @args: The integer to print.
 *
 * Return: The lenght of the integer to print.
 */
unsigned int print_int(va_list args)
{
	int i = va_arg(args, int);
	unsigned int count = 0;
	int tens = 1;

	if (i < 0)
	{
		putchar('-');
		count++;
	}
	if (i != 0)
	{
		j = i / 10;
		for (; j / tens != 0; count++)
			tens *= 10;
		for (; tens != 0; tens /= 10)
		{
			if (i >= 0)
				putchar(((i / tens) % 10)+ '0');
			else
				putchar((-(i / tens) % 10)+ '0');
		}
	}
	else
	{
		putchar(i);
		count = 1;
	}
}
