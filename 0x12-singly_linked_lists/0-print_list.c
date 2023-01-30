#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints length and the string, then returns amount of nodes
 * @h: pointer to a struct constant
 *
 * Return: amount of node
 */
size_t print_list(const list_t *h)
{
	unsigned int count = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[%u] %s\n", 0, "(nil)");
		else
			printf("[%u] %s\n", h->len, h->str);

		h = h->next;
		count++;
	}

	return (count);
}
