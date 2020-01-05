#include "monty.h"
/**
* getlines - functions get the information.
* @head: The new node.
* @av: arguments.
* Return: nothing.
*/
void getlines(stack_t **head, char **av)
{
	char *buf;
	FILE *fd;
	size_t size = 1024;
	int lines_cont = 0;

	fd = fopen(av[1], "r");
	if (!fd)
	{
		dprintf(STDERR_FILENO, "Error: Can't open %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	buf = malloc(sizeof(char) * size);
	if (buf == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (getline(&buf, &size, fd) != EOF)
	{
		if (strcmp(buf, "\n") != 0)
			verification(head, buf, lines_cont + 1, fd);
		lines_cont++;
	}
	free(buf);
	fclose(fd);
}
