#include "main.h"

/**
 * print_buffer - Adds a character to the buffer and flushes it if full.
 * @c: The character to add to the buffer.
 * @buffer: The buffer storing characters before writing.
 * @add: Pointer to the index of the next free position in the buffer.
 *
 * Return: Always 1 (success).
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
