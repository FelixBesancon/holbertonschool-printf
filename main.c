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
	int a, b;

	a = _printf("Let's try to printf a %%!\n");
	b = printf("Let's try to printf a %%!\n");
	printf("_printf is : %d\nprintf is : %d\n\n", a, b);
	a = _printf("Let's try to printf a simple sentence%%.\n");
	b = printf("Let's try to printf a simple sentence%%.\n");
	printf("_printf is : %d\nprintf is : %d\n\n", a, b);
	a = _printf("Test : %c %c %c", 'A', 'a', '\n');
	b = printf("Test : %c %c %c", 'A', 'a', '\n');
	printf("_printf is : %d\nprintf is : %d\n\n", a, b);
	a = _printf("Text is string : %s", "this is a string.\n");
	b = printf("Text is string : %s", "this is a string.\n");
	printf("_printf is : %d\nprintf is : %d\n\n", a, b);
	a = _printf("Let's print an int %d, %i, %d!\n", 12345, -999, 595959);
	b = printf("Let's print an int %d, %i, %d!\n", 12345, -999, 595959);
	printf("_printf is : %d\nprintf is : %d\n\n", a, b);
	a = _printf("Let's print int min %d and int max %d!\n", INT_MIN, INT_MAX);
	b = printf("Let's print int min %d and int max %d!\n", INT_MIN, INT_MAX);
	printf("_printf is : %d\nprintf is : %d\n\n", a, b);
	a = _printf("iddi%diddiiddi\n", 1024);
	b = printf("iddi%diddiiddi\n", 1024);
	printf("_printf is : %d\nprintf is : %d\n\n", a, b);
	a = _printf("Test a null string: %s\n", (char *)0);
	b = printf("Test a null string: %s\n", (char *)0);
	printf("_printf is : %d\nprintf is : %d\n\n", a, b);
	a = _printf("%");
	b = printf("%");
	printf("_printf is : %d\nprintf is : %d\n\n", a, b);
	a = _printf("%!\n");
	b = printf("%!\n");
	printf("_printf is : %d\nprintf is : %d\n\n", a, b);
	a = _printf("%K\n");
	b = printf("%K\n");
	printf("_printf is : %d\nprintf is : %d\n\n", a, b);
	a = _printf("Let's print a %% insi%%de %s!\n", "a sentence");
	b = printf("Let's print a %% insi%%de %s!\n", "a sentence");
	printf("_printf is : %d\nprintf is : %d\n\n", a, b);
	a = _printf("Let's print a binary number %b and %b.\n", 17, 98);
	b = printf("Let's print a binary number %b and %b.\n", 17, 98);
	printf("_printf is : %d\nprintf is : %d\n\n", a, b);
	a = _printf("Let's print two great unsigned int : %u and %u.\n", 5555555555, -1234);
	b = printf("Let's print two great unsigned int : %u and %u.\n", 5555555555, -1234);
	printf("_printf is : %d\nprintf is : %d\n\n", a, b);
	a = _printf("Let's print an unsigned int in octal : %o and %o.\n", 5555555555, -1234);
	b = printf("Let's print an unsigned int in octal : %o and %o.\n", 5555555555, -1234);
	printf("_printf is : %d\nprintf is : %d\n\n", a, b);
	a = _printf("Let's print an unsigned int in hexadecimal : %x and %x.\n", 5555555555, 15);
	b = printf("Let's print an unsigned int in hexadecimal : %x and %x.\n", 5555555555, 15);
	printf("_printf is : %d\nprintf is : %d\n\n", a, b);
	_printf("Let's print an unsigned int in hexadecimal : %X and %X.\n", 5555555555, 15);
	b = printf("Let's print an unsigned int in hexadecimal : %X and %X.\n", 5555555555, 15);
	printf("_printf is : %d\nprintf is : %d\n\n", a, b);
	return (0);
}
