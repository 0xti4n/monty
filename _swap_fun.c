#include "monty.h"
/**
 * pint_fun - prints the value at the top of the stack, followed by a new line.
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
