#include "lists.h"

/**
 * pop_listint - deletes head node
 * @head: Pointer to pointer to the head node of the linked list.
 *
 * Return: The head node's data (n), 0 if fails
 */
int pop_listint(listint_t **head)
{
    int data;
    listint_t *temp;

    if (*head == NULL) {
        return 0;
    }

    temp = *head;
    data = temp->n;
    *head = (*head)->next;
    free(temp);

    return data;
k
