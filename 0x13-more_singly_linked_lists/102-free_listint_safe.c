#include "lists.h"

/**
 * free_listp2 - frees a linked list
 * @head: head of a list
 *
 * Return: no return
 */
void free_listp2(listp_t **head)
{
	listp_t *temp;
	listp_t *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}
