#include "monty.h"
/**
 * pchar_fun - change integer to char in the top stack.
 * @line_number: integer line number
 * @stack: pointer to pointer to stack header(or queue)
 * Return: nothing
 */

void pchar_fun(stack_t **stack, unsigned int line_number)
{
	if (stack ==  NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n >= 0 && (*stack)->n <= 255)
	{
		printf("%c\n", (*stack)->n);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}
