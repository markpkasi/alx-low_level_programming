#include "main.h"
/**
 * _islower - checks for lowercase character, if YES returns 1 otherwise returns 0
 * @c: int value to be compared with the ASCII value
 * Return 0 (Success)
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')

	{
		return (1);
	}
	else

	{
		return (0);
	}
	_putchar('\n');
}
