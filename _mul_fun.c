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
	int mul = 0, mul2 = 0;

	if (stack ==  NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	mul = (*stack)->n;
	mul2 = (*stack)->next->n;
	*stack = (*stack)->next;
	(*stack)->n = mul * mul2;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
