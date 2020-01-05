#include "monty.h"
char *filter_num(char * instruction)
{
	int i = 0;

	while (instruction[i])
	{
		if (!(instruction[i] >= 48 && instruction[i] <= 57) && instruction[i] != '-')
			return (NULL);
		i++;
	}
	return (instruction);
}
/**
* verification: verificate the information and execute.
* @head: The new node.
* @line: The getline.
* Return: Nothing.
*/
void verification(stack_t **head, char *line, int n_line, FILE *fd)
{
	int n_op = 0, not_match = 0;
	char **instructions = NULL;

	instruction_t comands[] = {
		{"push", add_stack},
		{"pall", print_all},
		{NULL, NULL}
	};
	instructions = tokenize(line);
	while (comands[n_op].opcode && instructions)
	{
		if (strcmp(comands[n_op].opcode, instructions[0]) == 0)
		{
			if (strcmp(comands[n_op].opcode, "pall") != 0)
			{	
				if (instructions[1] == NULL || filter_num(instructions[1]) == NULL)
				{
					dprintf(STDERR_FILENO, "L %d: usage: push integer\n", n_line);
					free(instructions);
					free_stack(*head);
					fclose(fd);
					free(line);
					exit (EXIT_FAILURE);
				}
				n = atoi(instructions[1]);
			}
			comands[n_op].f(head, n_line);
		}
		else
			not_match++;
		n_op++;
	}
	if (not_match == n_op && instructions != NULL)
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", n_line, instructions[0]);
		free(instructions);
		free_stack(*head);
		fclose(fd);
		free(line);
		exit (EXIT_FAILURE);
	}
	free(instructions);
}
