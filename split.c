#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * split_line - splits the input line into command and arguments.
 * @line: the line of string to be splitted.
 * Return: splitted string.
 */

char **split_line(char *line)
{
	char *token, **tokens;
	size_t bufsize, i;

	bufsize = TOK_BUFSIZE;
	tokens = malloc(bufsize * sizeof(char *));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, "Allocation Error\n", 16);
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOK_DELIM);
	tokens[0] = token;
	for (i = 1; token != NULL; i++)
	{
		if (i == bufsize)
		{
			bufsize += TOK_BUFSIZE;
			tokens = _realloc(tokens, i, bufsize * sizeof(char *));
			if (tokens == NULL)
			{
				write(STDERR_FILENO, "Allocation Error\n", 16);
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
		tokens[i] = token;
	}
	return (tokens);
}
