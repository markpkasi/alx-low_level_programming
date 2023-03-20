#include "main.h"
#include <stdio.h>

/**
 * _isdigit - checks for a digit 0 to 9
 * @c: parameter
 * Return: 1 if c is a digit, otherwise 0
 */

int _isdigit(int c)
{
	int a;

	for (a = '0'; a <= '9'; a++)
	{
		if (a == c)
		{
			return (1);
		}
	}

	return (0);
}
