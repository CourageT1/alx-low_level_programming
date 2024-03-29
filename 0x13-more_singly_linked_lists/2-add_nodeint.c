#include "lists.h"

/**
 * add_nodeint - adds a new node
 * @head: pointer to the first node
 * @n: data to insert in that new node
 *
 * Return: pointer to a new node,NULL if it fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *new_node;
new_node = malloc(sizeof(listint_t));

if (new_node == NULL)
return (NULL);

new_node->n = n;
new_node->next = *head;
*head = new_node;

return (new_node);
}
