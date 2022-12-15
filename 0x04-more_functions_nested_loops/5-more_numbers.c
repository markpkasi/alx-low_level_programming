#include "main.h"

/**
 * more_numbers - prints 10 times the number from 0 to 14
 * followed by a new line
 * _prints only 3 times
 * Return: 0-14 x10 followed by a new line
 */

void more_numbers(void)
{
	int a, b;

	for (b = 0; b < 10; b++)
	{
		for (a = 0; a <= 14; a++)
		{
			if (a >= 10)
			{
				_putchar((a / 10) + '0');
			}
			_putchar((a % 10) + '0');
		}
		_putchar('\n');
	}
}
