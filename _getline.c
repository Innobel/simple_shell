#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

ssize_t _getline(char **input, size_t *n, FILE *stream)
{
	size_t capacity = *n;
	char *temp;
	int ch;
	size_t read = 0;

	if (input == NULL || n == NULL)
		return (-1);
	if (*input == NULL)
	{
		*input = malloc(capacity);
		if (*input == NULL)
		{
			perror("Error: malloc\n");
			return (-1);
		}
	}

	while ((ch = fgetc(stream)) != EOF && ch != '\n')
	{
		(*input)[read++] = (char)ch;
		if (read + 1 >= capacity)
		{
			capacity *= 2;
			temp = realloc(*input, capacity);
			if (temp == NULL)
			{
				perror("./shell: ");
				return (-1);
			}
			*input = temp;
		}
	}
	(*input)[read] = '\0';
	*n = capacity;
	if(ch == EOF && read == 0)
		return (-1);
	return ((ssize_t)read); }
