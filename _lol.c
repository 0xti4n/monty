#include "monty.h"

int n = 0;
/**
* main: main function
* @ac: integer
* @av: arguments
* Return: 0 if success
*/
int main(int ac, char **av)
{
	stack_ *head = NULL;
	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	getlines(&head, av);
	free_stack(head);
	return (0);
}
