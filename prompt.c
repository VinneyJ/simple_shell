#include "holberton.h"
#include <stdio.h>


/**
 * _readline - reads input commands and parameters from user.
 * Return: the line entered by the user.
 */

char *_readline(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;

	write(STDIN_FILENO, "$ ", 2);
	if (getline(&buffer, &bufsize, stdin) == -1)
	{
		write(STDIN_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	return (buffer);
}
