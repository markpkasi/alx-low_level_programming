#include "main.h"

/**
 * print_numbers - prints numbers from 0 to 9
 */

void print_numbers(void)
{
	int r;

	for (r = '0'; r <= '9'; r++)
	{
		_putchar(r);
	}
	_putchar('\n');
}
