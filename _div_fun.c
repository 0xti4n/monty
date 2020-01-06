#include "monty.h"
/**
 * div_fun - div two top stack elements.
 * @line_number: integer line number
 * @stack: pointer to pointer to stack header(or queue)
 * Return: nothing
 */

void div_fun(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int div = 0, div2 = 0;

	if (stack ==  NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	div = (*stack)->n;
	if (div == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	div2 = (*stack)->next->n;
	*stack = (*stack)->next;
	(*stack)->n = div2 / div;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
