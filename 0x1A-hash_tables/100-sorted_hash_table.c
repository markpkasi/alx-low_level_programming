#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the new sorted table
 * Return: NULL on error, otherwise
 *         a pointer to the new sorted hash table
 * Description: Create sorted hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
        hash_table_t *hash_table_created;
        unsigned long int j;

        /* allocate memory space for the hash table*/
        hash_table_created = malloc(sizeof(hash_table_t));

        if (hash_table_created == NULL)
                return (NULL);
        hash_table_created->size = size;
        hash_table_created->array = malloc(sizeof(hash_node_t *) * size);

        if (hash_table_created->array == NULL)
                return (NULL);
        for (j = 0; j < size; j++)
        {
                hash_table_created->array[j] = NULL;
        }
        return (hash_table_created);
}

/**
 * hash_table_set - adds/updates an element in a hash table
 * @ht: hast table to add/update key/value to
 * @key: the key to add unempty string
 * @value: the value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
        hash_node_t *new;
        char *value_copy;
        unsigned long int index, j;

        if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
                return (0);
        value_copy = strdup(value);
        if (value_copy == NULL)
                return (0);

        index = key_index((const unsigned char *)key, ht->size);
        for (j = index; ht->array[j]; j++)
        {
                if (strcmp(ht->array[j]->key, key) == 0)
                {
                        free(ht->array[j]->value);
                        ht->array[j]->value = value_copy;
                        return (1);
                }
        }
        new = malloc(sizeof(hash_node_t));
        if (new == NULL)
        {
                free(value_copy);
                return (0);
        }
        new->key = strdup(key);
	 if (new->key == NULL)
        {
                free(new);
                return (0);
        }
        new->value = value_copy;
        new->next = ht->array[index];
        ht->array[index] = new;
        return (1);
}

/**
 * hash_table_get - function to Retrieve the value associated with
 *                  a key in a hash table
 * @ht: pointer to the hash table
 * @key: key to get the value of
 *
 * Return: the value associated with the element, or NULL if key
 *         could not be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
        hash_node_t *node;
        unsigned long int index;

        if (ht == NULL || key == NULL || *key == '\0')
                return (NULL);
        index = key_index((const unsigned char *)key, ht->size);
        if (index >= ht->size)
                return (NULL);
        node = ht->array[index];
        while (node && strcmp(node->key, key) != 0)
                node = node->next;

        return ((node == NULL) ? NULL : node->value);
}

/**
 * hash_table_print - function thatprints hash table
 * @ht: pointer to the hash table to print
 *
 * Description: print the key/value in the order that
 *              they appear in the array of hash table
 * Return: print, if ht is NULL, don’t print
 */
void hash_table_print(const hash_table_t *ht)
{
        hash_node_t *node;
        unsigned long int j;
        unsigned char comma_flag = 0;

        if (ht == NULL)
                return;
        printf("{");
        for (j = 0; j < ht->size; j++)
        {
                if (ht->array[j] != NULL)
                {
                        if (comma_flag == 1)
                                printf(", ");
                        node = ht->array[j];
                        while (node != NULL)
                        {
                                printf("'%s': '%s'", node->key, node->value);
                                node = node->next;
                                if (node != NULL)
                                        printf(", ");
                        }
                        comma_flag = 1;
                }
        }
        printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: A pointer to the sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->stail;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * hash_table_delete - function that deletes a hash table
 * @ht: A pointer to a hash table
 */
void hash_table_delete(hash_table_t *ht)
{
        hash_table_t *head = ht;
        hash_node_t *node, *tmp;
        unsigned long int j;

        for (j = 0; j < ht->size; j++)
        {
                if (ht->array[j] != NULL)
                {
                        node = ht->array[j];
                        while (node != NULL)
                        {
                                tmp = node->next;
                                free(node->key);
                                free(node->value);
                                free(node);
                                node = tmp;
                        }
                }
        }
        free(head->array);
        free(head);
}
