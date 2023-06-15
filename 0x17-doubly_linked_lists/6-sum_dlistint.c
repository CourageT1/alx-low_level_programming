#include "lists.h"

/**
 * sum_dlistint -  a function that returns the sum of all the data (n)
 * @head: pointer to the head
 *
 * Return: if the list is empty - 0
 */
int sum_dlistint(dlistint_t *head)
{
int sum = 0;
dlistint_t *current = head;

while (current != NULL)
{
sum += current->n;
current = current->next;
}
return (sum);
}
