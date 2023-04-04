#include "lists.h"

/**
 * listint_len - returns number of elements
 * @h: linked list of type listint_t
 *
 * Return: Number of nodes
 */
size_t listint_len(const listint_t *h)
{
size_t count = 0;
while (h != NULL)
{
count++;
h = h->next;
}
return (count);
}
