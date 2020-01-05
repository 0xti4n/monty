#include "monty.h"

/**
* tokenize: parse the information of the file.
* @line: The info to tokenize.
* Return: The list of tokens.
*/
char **tokenize(char *line)
{
	char **instructions = NULL, del[7] = " \t\r\n\a";
	char *token = NULL;
	int i = 0;

	instructions = malloc(sizeof(char *) * 2);
	if (!instructions)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \t\n"); /* no olvidar tab y los demas sep */
	if (token == NULL)
		return (NULL);
	if (strcmp(token, "push") == 0)
		instructions[1] = NULL;
	while (i < 2)
	{
		instructions[i] = token;
		token = strtok(NULL, del);
		i++;
	}
	return (instructions);
}
