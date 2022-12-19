#include <stdio.h>
#include <string.h>
#include "main.h"
/**
 * print_rev - prints a string, in reverse, followed by a new line
 *
 * @s: string to reverse
 * Return: nothing
 */

void print_rev(char *s)
{
	int len = strlen(s);

	while (len--)
		putchar(*(s + len));
	putchar(10);
}
