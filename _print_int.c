#include "main.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int i = 123456, j;
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
		for (count = 0; j / tens != 0; count++)
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
	
	printf("\ni = %d\ntens = %d\ncount = %d\n", i, tens, count);

	i = -1234;
	tens = 1;
	count = 0;
	if (i < 0)
	{
		putchar('-');
		count++;
	}
	if (i != 0)
	{
		j = i / 10;
		for (count = 0; j / tens != 0; count++)
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
	
	printf("\ni = %d\ntens = %d\ncount = %d\n", i, tens, count);

	i = INT_MIN;
	tens = 1;
	count = 0;
	if (i < 0)
	{
		putchar('-');
		count++;
	}
	if (i != 0)
	{
		j = i / 10;
		for (count = 0; j / tens != 0; count++)
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
	
	printf("\ni = %d\ntens = %d\ncount = %d\n", i, tens, count);

}
