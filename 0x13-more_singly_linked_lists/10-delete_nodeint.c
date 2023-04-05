#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node.
 * @head:Pointer to a pointer.
 * @index: The index of the node to be deleted
 * Return: 1 if node successfully deletes,if not -1
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *current, *prev;
unsigned int i;

if (*head == NULL)
return (-1);
current = *head;
if (index == 0)
{
*head = current->next;
free(current);
return (1);
}
prev = NULL;
for (i = 0; i < index; i++)
{
if (current->next == NULL)
return (-1);
}
prev = current;
current = current->next;
prev->next = current->next;
free(current);
return (1);
}
