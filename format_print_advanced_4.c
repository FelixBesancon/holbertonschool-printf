#include "main.h"

/**
 * _putchar - Writes the character 'c' to stdout.
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_buffer(char c, char *buffer, int *add)
{

		if (*add >= 1023)
		{
			write(1, buffer, *add);
			*add = 0;
		}
		buffer[*add] = c;
		(*add)++;
		return(1);
}
