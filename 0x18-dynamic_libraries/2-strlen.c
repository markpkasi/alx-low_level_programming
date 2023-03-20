#include "main.h"
/**
 * _strlen - a program that returns the length of a string
 * @s: parameter
 * Return: Length as an integer
 */

int _strlen(char *s)
{
	int len = 0;

	while (*(s + len) != '\0')
		len++;

	return (len);
}
