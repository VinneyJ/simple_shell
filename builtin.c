#include "holberton.h"


/**
 * shell_exit - frees @args and exits the shell.
 * @args: the array of commands entered by user..
 * Return: Void.
 */

void shell_exit(char **args)
{
	free_dbl_ptr(args);
	exit(EXIT_SUCCESS);
}

/**
 * _env - prints the environmental variables.
 * @environ: the environmental variables.
 * Return: 0 on success.
 */

void _env(char **environ)
{
	unsigned int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
