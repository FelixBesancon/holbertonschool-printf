#include "main.h"

/**
* print_HEXA_rec - Prints recursively an unsigned int
* converted into capital hexadecimal.
* @X: The unsigned int to convert and print.
*
* Return: The length of the number printed.
*/
int print_HEXA_rec(unsigned int X)
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

/**
 * print_STRING - Prints a string of characters, prints (null)
 * if the string is NULL, prints '\x' followed by the ASCII code
 * value in capital hexadecimal of each non-printable character.
 * @args: The string to print.
 *
 * Return: The length of the string to print.
 */
int print_STRING(va_list args)
{
	int count = 0;
	unsigned int char_S;
	char *S = va_arg(args, char *), *null_STRING = "(null)";

	if (S == NULL)
	{
		for (; *null_STRING != '\0'; null_STRING++, count++)
			_putchar(*null_STRING);
	}
	else
	{
		for (; *S != '\0'; S++, count++)
			if (*S > 31 && *S < 127)
				_putchar(*S);
			else
			{
				char_S = *S;
				_putchar('\\'), _putchar('x');
				if (char_S < 16)
					{ _putchar('0'), count++; }
				count += 1 + print_HEXA_rec(char_S);
			}
	}
	return (count);
}

/**
* print_adress_rec - Prints recursively an unsigned long
* converted into hexadecimal.
* @address: The unsigned long to convert and print.
*
* Return: The length of the address printed.
*/
int print_adress_rec(unsigned long address)
{
	int count;

	if (address < 16)
	{
		if (address > 9)
			_putchar('0' + (address + 39));
		else
			_putchar('0' + address);
		return (1);
	}
	count = print_adress_rec(address / 16);
	if ((address % 16) > 9)
		_putchar('0' + ((address % 16) + 39));
	else
		_putchar('0' + (address % 16));
	return (count + 1);
}

/**
 * print_pointer - Prints the address of a pointerin hexadecimal,
 * starting with 'ox', prints '(nil)' if the pointer is NULL.
 * @args: The address to print.
 *
 * Return: The length of the string to print.
 */
int print_pointer(va_list args)
{
	int count = 0;
	char *null_pointer = "(nil)";
	unsigned long address;
	void *p = va_arg(args, void *);

	if (p == NULL)
	{
		for (; *null_pointer != '\0'; null_pointer++, count++)
			_putchar(*null_pointer);
	}
	else
	{
		address = (unsigned long)p;
		_putchar('0'), _putchar('x');
		count += 2 + print_adress_rec(address);
	}
	return (count);
}
