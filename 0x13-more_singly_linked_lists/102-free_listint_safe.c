#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a linked list of integers
 * @h: Pointer to pointer to the head of the list
 *
 * Return: The number of nodes in the list
 */
size_t free_listint_safe(listint_t **h)
{
listint_t *current, *tmp;
size_t count = 0;

if (h == NULL)
return (0);

current = *h;
*h = NULL;

while (current != NULL)
{
count++;
if (current <= current->next)
{
free(current);
break;
}
tmp = current;
current = current->next;
free(tmp);
}
return (count);
}
