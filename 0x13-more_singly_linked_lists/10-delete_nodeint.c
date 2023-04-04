/**
 * delete_nodeint_at_index - Deletes the node at index of a linked list.
 * @head: Pointer to a pointer to the head node of the linked list.
 * @index: The index of the node that should be deleted. Index starts at 0.
 *
 * Return: 1 if the node is successfully deleted, or -1 otherwise.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    listint_t *current, *prev;
    unsigned int i;

    if (*head == NULL) {
        return (-1);  // The list is empty.
    }

    current = *head;

    if (index == 0) {
        *head = current->next;  // Update the head node.
        free(current);
        return (1);
    }

    prev = NULL;

    for (i = 0; i < index; i++) {
        if (current->next == NULL) {
            return (-1);  // Index is out of range.
        }
        prev = current;
        current = current->next;
    }

    prev->next = current->next;
    free(current);
    return (1);
}
