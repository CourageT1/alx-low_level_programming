#include "lists.h"

/**
 * add_nodeint - adds a new node
 * @head: pointer to the first node
 * @data: data to insert in that new node
 *
 * Return: pointer to a new node
 */
listint_t *add_nodeint(listint_t **head, cons int data);
{
new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);
new_node->data = data;
new_node->next = *head;
*head = new_node;
return (new);
}
