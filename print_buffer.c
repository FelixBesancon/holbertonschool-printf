#include "main.h"

/**
 * print_buffer - WStores a character in an output buffer and flushes it
 * to stdout when the buffer is full.
 * @c: The character to add to the buffer.
 * @buffer: The buffer used to store characters before writing.
 * @add: Pointer to the current number of characters stored in the buffer.
 *
 * Return: 1 on success, or -1 if write fails when flushing the buffer.
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
