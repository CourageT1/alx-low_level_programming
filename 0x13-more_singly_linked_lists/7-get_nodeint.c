#include "lists.h"

/**
 * get_nodeint_at_index - returns the node
 * @head: pointer to the head of the list
 * @index: index of the node to return
 *
 * Return: pointer to the nod, NULL if node does not exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
    listint_t *current = head;

    while (current != NULL && index > 0)
    {
        current = current->next;
        index--;
    }

    return current == NULL ? NULL : current;
}
