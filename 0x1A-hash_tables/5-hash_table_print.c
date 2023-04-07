#include "./hash_tables.h"

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
