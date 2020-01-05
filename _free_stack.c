#include "monty.h"
/**
 * free_stack - function that stack.
 * @head: pointer to head of list.
 *
 * Return: Void.
 */
void free_stack(stack_t *head)
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
