#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using the insertion sort
 *                       algorithm.
 *
 * @list: A pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *next, *prev;

	/* for empty list or list with single node */
	if (!(*list) || !list || !(*list)->next)
		return;

	current = (*list)->next;
	/* loop to traverse linked list */
	while (current)
	{
		temp = current;
		current = current->next;

		/* loop to swap nodes */
		while (temp->prev && (temp->n < temp->prev->n))
		{
			prev = temp->prev;
			next = temp->next;

			if (prev->prev)
				prev->prev->next = temp;
			else
				*list = temp;

			temp->prev = prev->prev;
			temp->next = prev;
			prev->prev = temp;
			prev->next = next;

			if (next)
				next->prev = prev;

			print_list(*list); /* prints list for every successful swap */
		}
	}
}
