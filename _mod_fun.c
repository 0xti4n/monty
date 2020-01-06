#include "monty.h"
/**
 * mod_fun - div two top stack elements.
 * @line_number: integer line number
 * @stack: pointer to pointer to stack header(or queue)
 * Return: nothing
 */

void mod_fun(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int mod = 0, mod2 = 0;

	if (stack ==  NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	mod = (*stack)->n;
	if (mod == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	mod2 = (*stack)->next->n;
	*stack = (*stack)->next;
	(*stack)->n = mod2 % mod;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
