#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t list
 * @head: double pointer to the head of the list
 * @index: index of the node to delete
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *tmp;
    unsigned int i = 0;

    if (head == NULL || *head == NULL)
        return (-1);

    tmp = *head;

    /* cas où on supprime le premier élément */
    if (index == 0)
    {
        *head = tmp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(tmp);
        return (1);
    }

    /* avancer jusqu'au nœud à supprimer */
    while (tmp != NULL && i < index)
    {
        tmp = tmp->next;
        i++;
    }

    if (tmp == NULL) /* index trop grand */
        return (-1);

    /* relier les maillons voisins */
    if (tmp->prev != NULL)
        tmp->prev->next = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = tmp->prev;

    free(tmp);
    return (1);
}
