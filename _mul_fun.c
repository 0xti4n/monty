#include "monty.h"
/**
 * mul_fun - mul two top stack elements.
 * @line_number: integer line number
 * @stack: pointer to pointer to stack header(or queue)
 * Return: nothing
 */

void mul_fun(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int sum = 0;

	if (stack ==  NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->n *= sum;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
