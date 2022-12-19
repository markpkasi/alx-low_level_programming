#include "main.h"
/**
 * swap_int - a program that swaps the values of two integers
 * @a: parameter
 * @b: parameter
 * Return: Always 0 (Success)
 */

void swap_int(int *a, int *b)
{
	int r = *a;

	*a = *b;
	*b = r;
}
