#include "lists.h"

/**
 * sum_listint - calcultes the sum of all data
 * @head: first node
 * Return: sum
 */
int sum_listint(listint_t *head)
{
int sum = 0;

while (head != NULL)
{
sum += head->n;
head = head->next;
}
return (sum);
}
