#include <stdlib.h>
#include "lists.h"
/**
 * free_listint2 - frees a linked list
 * @head: pointer to the listint_t list
 */
void free_listint2(listint_t **head)
{
listint_t *current = *head;
listint_t *next;

if (head == NULL)
return;

while (current != NULL)
{
next = current->next;
free(current);
current = next;
}
*head = NULL;
}
