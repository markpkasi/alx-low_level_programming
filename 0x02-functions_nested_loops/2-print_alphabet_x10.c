#include "main.h"

/**
 * print_alphabet_x10 - a function that prints a - z 10 times
 * main - Entry point
 * Return: 0 (Success)
 */

void print_alphabet_x10(void)
{
	int x = 1;
	char la;

	for (x = 1; x <= 10; x++)
	{
		for (la = 'a'; la <= 'z'; la++)
			_putchar(la);
		_putchar('\n');
	}
}
