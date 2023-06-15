#include "lists.h"

/**
 * get_dnodeint_at_index -  function that returns the nth node
 * @head: pointer to the head
 * @index:  index of the node
 * Return: if the node does not exist, NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
dlistint_t *current = head;
unsigned int count = 0;

while (current != NULL)
{
if (count == index)
{
return (current);
}
count++;
current = current->next;
}
return (NULL);
}
