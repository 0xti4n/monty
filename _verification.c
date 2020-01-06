#include "monty.h"
/**
* free_error - Functions that free the information.
* @ins: the instructions.
* @head: The stack.
* @fd: The file.
* @line: The buf.
* Return: Exit failure.
*/
void free_error(char **ins, stack_t **head, FILE *fd, char *line)
{
	free(ins);
	free_stack(*head);
	fclose(fd);
	free(line);
	exit(EXIT_FAILURE);
}

/**
* filter_num - Functions that filter the information.
* @instruction: instructions
* Return: Null if not match.
*/
char *filter_num(char *instruction)
{
	int i = 0;

	while (instruction[i])
	{
		if (!(instruction[i] >= 48 && instruction[i] <= 57) && instruction[0] != '-')
			return (NULL);
		i++;
	}
	return (instruction);
}
/**
* verification -verificate the information and execute.
* @head: The new node.
* @line: The getline.
* @n_line: NUmber of line.
* @fd: The file.
* Return: Nothing.
*/
void verification(stack_t **head, char *line, int n_line, FILE *fd)
{
	int n_op = 0, not_match = 0;
	char **ins = NULL;

	instruction_t comands[] = {
		{"push", add_stack},
		{"pall", print_all},
		{"pint", pint_fun},
		{"pop", pop_fun},
		{"swap", swap_fun},
		{"add", add_fun},
		{"nop", nop_fun},
		{NULL, NULL}
	};
	ins = tokenize(line);
	while (comands[n_op].opcode && ins)
	{
		if (strcmp(comands[n_op].opcode, ins[0]) == 0)
		{
			if (strcmp(comands[n_op].opcode, "push") == 0)
			{
				if (ins[1] == NULL || filter_num(ins[1]) == NULL)
				{
					dprintf(STDERR_FILENO, "L%d: usage: push integer\n", n_line);
					free_error(ins, head, fd, line);
				}
				n = atoi(ins[1]);
			}
			comands[n_op].f(head, n_line);
		}
		else
			not_match++;
		n_op++;
	}
	if (not_match == n_op && ins != NULL)
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", n_line, ins[0]);
		free_error(ins, head, fd, line);
	}
	free(ins);
}
