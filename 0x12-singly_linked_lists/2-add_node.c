#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * _strlen - length of the passed string
 * @s: string
 *
 * Return: length of a string
 */

int _strlen(const char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
		i++;

	return (i);
}

/**
 * add_node - prints length and string, then returns amount of nodes
 * @head: pointer to a struct constant
 * @str: haha ex di
 *
 * Return: amount of node
 */
list_t *add_node(list_t **head, const char *str)
{

	list_t *newNode;

	newNode = malloc(sizeof(newNode));
	if (newNode == NULL)
		return (NULL);
	if (str == NULL)
	{
		free(newNode);
		return (NULL);
	}
	newNode->len = _strlen(str);
	newNode->str = strdup(str);
	newNode->next = *(head);
	*head = newNode;

	return (newNode);
}
