#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	_printf("Let's try to printf a %%!\n");
	printf("Let's try to printf a %%!\n");
	_printf("Let's try to printf a simple sentence.\n");
	printf("Let's try to printf a simple sentence.\n");
	_printf("Test : %c %c %c", 'A', 'a', '\n');
	printf("Test : %c %c %c", 'A', 'a', '\n');
	_printf("Text is string : %s", "this is a string.\n");
	printf("Text is string : %s", "this is a string.\n");
	return (0);
}
