#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name - function that prints a name passed on it
 * @name: char to display to the stdout
 * @f: a pointer function
 * Return: nothing (VOID declared as R_TYPE)
 */

void print_name(char *name, void (*f)(char *))
{
	if (!name || !f) /* if any is NULL */
		return;

	f(name);
}
