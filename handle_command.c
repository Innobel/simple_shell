#include "main.h"

/**
 * handle_command - Execute the given command in the child process
 * @input: the command to be excuted.
 * Return: Nothing.
 */

void handle_command(char *input)
{
	char *token;
	int i = 0;
	char **array_hold = malloc(sizeof(char *) * 1024);

	if (array_hold == NULL)
	{
		perror("./shell: ");
		exit(EXIT_FAILURE);
	}
	token = strtok(input, " ");
	
	while (token != NULL)
	{
		array_hold[i++] = token;
		token = strtok(NULL, " ");
	}

	array_hold[i++] = NULL;
	
	/* This is to make sure NULL is passed to in the second argument of execve */
	if (execve(array_hold[0], array_hold, NULL) == -1)
	{
		perror("./shell: ");
		exit(EXIT_FAILURE);
	}

	free(array_hold);
}
