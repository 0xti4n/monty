#include "monty.h"
/**
 * free_dlistint - doubly linked list
 * @head: pointer to head of list.
 *
 * Return: Void.
 */
void free_stack(stack_ *head)
{
	if (head == NULL)
		return;
	while (head->next)
	{
		head = head->next;
		free(head->prev);
	}
	free(head);
}
