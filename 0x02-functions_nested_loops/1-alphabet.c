#include "main.h"

/**
 * print_alphabet - function that prints alphabets lowercase
 * Return: Always 0 (Success)
 **/

void print_alphabet(void)
{
	int n;

	for (n = 'a'; n <= 'z'; n++)
	{
		_putchar(n);
	}
	_putchar('\n');
}
