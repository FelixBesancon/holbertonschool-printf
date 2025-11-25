#include "main.h"
 * print_char - Prints a single character.
 * @args: The character to print.
 *
 * Return: Void.
 */
void print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
}
/**
 * print_string - Prints a string of characters.
 * @args: The string to print.
 *
 * Return: Void.
 */
void print_string(va_list args)
{
	int i;
	char *s = va_arg(args, char *);

	if (s != NULL)
	{
		for (i = 0; s[i] != '\0'; i++)
			_putchar(s[i]);
	}
}
