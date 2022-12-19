#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * rev_string - function that reverses a string
 * @s: string
 * Return: Always 0 (Success)
 */

void rev_string(char *s)
{
	int l, i;

	char *begin_ptr, *end_ptr, ch;

	l = strlen(s);

	begin_ptr = s;

	end_ptr = s;

	for (i = 0; i < l - 1; i++)
		end_ptr++;

	for (i = 0; i < l / 2; i++)
	{
		ch = *end_ptr;
		*end_ptr = *begin_ptr;
		*begin_ptr = ch;

		begin_ptr++;

		end_ptr--;
	}
}
