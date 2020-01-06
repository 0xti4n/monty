#include "monty.h"
/**
 * swap_fun - swap top two elements of the stack.
 * @line_number: integer line number
 * @stack: pointer to pointer to stack header(or queuei)
 * Return: nothing
 */

void swap_fun(stack_t **stack, unsigned int line_number)
{
	int swap;

	if (stack ==  NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	swap = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = swap;
}
