#include "monty.h"
/**
 * add_stack: add nodes in stack
 * @stack: pinter to head of list
 * @line_number: integer to save in node.
 * Return: nothing.
 */
void add_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	line_number--;
	new = malloc(sizeof(stack_t));
	if (new == NULL || stack == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (*stack == NULL)
	{
		*stack = new;
		(*stack)->n = n;
		(*stack)->prev = NULL;
		(*stack)->next = NULL;
		
	}
	else
	{
		new->n = n;
		(*stack)->prev = new;
		new->next = *stack;
		new->prev = NULL;
		*stack = new;
	}
}
