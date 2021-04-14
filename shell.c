#include "holberton.h"
#include <stdio.h>

/**
 * main - shell program.
 * Return: 0 upon success.
 */

int main(void)
{
	char *line, **args;
	int status;

	do {
		line = _readline();
		args = split_line(line);
		if (_strcmp(args[0], "exit") == 0)
		{
			free(line);
			free(args);
			exit(EXIT_SUCCESS);
		}
		status = execute(args);

		free(line);
		free(args);
	} while (status);
	free(line);
	free(args);
	return (0);
}
