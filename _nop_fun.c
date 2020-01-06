#include "monty.h"
/**
 * nop_fun - delete top stack
 * @line_number: integer line number
 * @stack: pointer to pointer to stack header(or queuei)
 * Return: nothing
 */

void nop_fun(stack_t **stack, unsigned int line_number)
{
	**stack = **stack;
	line_number--;
}
