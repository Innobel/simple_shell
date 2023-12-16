#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
/**
 * main - Entry point for the simple shell.
 *
 * Return: 0 on succes.
 */

int main(void)
{
	pid_t my_child;
	int status;
	char *input;
	size_t n = 0;
	ssize_t nread;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		nread = getline(&input, &n, stdin); /* Handle Eof */
		if (nread == -1)
		{
			if (feof(stdin))
			{
				write(STDOUT_FILENO, "\n", 1);
				break;
			}
			perror("./shell: ");
			exit(EXIT_FAILURE);
		}
		/* remove the newline added by the getline function */
		input[nread - 1] = '\0';
		my_child = fork();
		if (my_child == -1)
		{
			perror("./shell: ");
			exit(EXIT_FAILURE);
		}
		/*child process */
		if (my_child == 0)
		{
			handle_command(input);
		}
		else /* parent process wait's */
		{
			wait(&status);
		}
	}
	return (0);
}
