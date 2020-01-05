#include "monty.h"
/**
 * print_all - prints all the elements of a stack.
 * @stack: list to print.
 * @line_number: number of line.
 * Return: nothing.
 */
void print_all(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	line_number--;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
