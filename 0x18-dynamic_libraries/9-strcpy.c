#include <stdio.h>
#include "main.h"

/**
 * _strcpy - a function that copies a string pointed to src and dest
 * @dest: pointer parameter
 * @src: pointer parameter
 * Return: char
 */

char *_strcpy(char *dest, char *src)
{
	int inc = 0;

	while (*(src + inc) != '\0')
	{
		*(dest + inc) = *(src + inc);
		inc++;
	}
	*(dest + inc) = '\0';

	return (dest);
}
