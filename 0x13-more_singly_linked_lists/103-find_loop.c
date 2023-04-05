#include "lists.h"

/**
 * find_listint_loop - Finds the loop.
 * @head: Pointer to the head node of the list.
 *
 * Return: Address of the node where loop starts, or NULL if not
 */
listint_t *find_listint_loop(listint_t *head)
{
listint_t *slow = head;
listint_t *fast = head;

while (fast != NULL && fast->next != NULL)
{
low = slow->next;
fast = fast->next->next;
if (slow == fast)
{
low = head;
while (slow != fast)
{
slow = slow->next;
fast = fast->next;
}
return (slow);
}
}
return (NULL);
}
