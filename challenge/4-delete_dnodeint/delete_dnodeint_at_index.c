#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head;
	dlistint_t *tmp;
	unsigned int p;

	if (head == NULL || *head == NULL)
		return (-1);

	saved_head = *head;
	p = 0;

	while (p < index && *head != NULL)
	{
		*head = (*head)->next;
		p++;
	}

	if (*head == NULL) /* index too large */
	{
		*head = saved_head;
		return (-1);
	}

	if (index == 0)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
		if (tmp != NULL)
			tmp->prev = NULL;
	}
	else
	{
		/* Relier les pointeurs correctement */
		if ((*head)->prev != NULL)
			(*head)->prev->next = (*head)->next;
		if ((*head)->next != NULL)
			(*head)->next->prev = (*head)->prev;

		free(*head);
		*head = saved_head;
	}

	return (1);
}

/*
 * Explication de la correction :
 * - Dans la version initiale, il était écrit :
 *       (*head)->prev->prev = (*head)->prev;
 *   Ce qui reliait le "grand-père" au lieu de mettre à jour
 *   le pointeur "next" du précédent.
 *
 * - Pour supprimer correctement un nœud au milieu d'une double liste :
 *     1. Le "prev->next" doit pointer vers "next".
 *     2. Le "next->prev" doit pointer vers "prev".
 *     3. Ensuite seulement, on libère le nœud.
 *
 * - Pour le cas particulier de l'index 0, on déplace simplement la tête
 *   sur l'élément suivant et on ajuste son "prev" à NULL.
 */
