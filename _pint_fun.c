#include "monty.h"
/**
 * pint_fun - prints the value at the top of the stack, followed by a new line.
 * @line_number: integer line number
 * @stack: pointer to pointer to stack header(or queuei)
 * Return: nothing
 */

void pint_fun(stack_t **stack, unsigned int line_number)
{
	if (stack ==  NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
