#include "lists.h"
#include <stdlib.h>

/**
 * _strlen - return the length from a string
 * @s: pointer to first character of a string
 * Return: number of characters in a string
 */

unsigned int _strlen(const char *s)
{
	unsigned int len = 0;

	while (*s)
	{
		len++;
		s++;
	}

	return (len);
}

/**
 * _strdup - returns a pointer to a copy of the string given as
 * a parameter
 * @str: string given as a parameter
 * Return: pointer to a copy of str
 */

char *_strdup(const char *str)
{
	unsigned int i, leng;
	char *s;

	if (str == NULL)
	{
		return (NULL);
	}
	else
	{
		for (i = 0; i < (leng + 1); i++)
		{
			s[i] = str[i];
		}
		return (s);
	}
}

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to the pointer of beginning of the list_t list
 * @str: string to be added
 * Return: new node added
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node = NULL, *current_node = NULL;

	new_node = (list_t *)malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->str = _strdup(str);
	new_node->len = _strlen(str);
	new_node->next = NULL;

	if (*head == NULL)
		*head = new_node;
	else
	{
		current_node = *head;
		while (current_node->next != NULL)
			current_node = current_node->next;
		current_node->next = new_node;
	}

	return (new_node);
}
