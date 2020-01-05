#include "monty.h"
/**
 * pop_fun - delete top stack
 * @line_number: integer line number
 * @stack: pointer to pointer to stack header(or queuei)
 * Return: nothing
 */

void pop_fun(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (stack ==  NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}
