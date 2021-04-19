#include "holberton.h"

/**
 * main - shell program.
 * @ac: the number of arguments passed.
 * @argv: a poiter to the name of the arguments passed.
 * Return: 0 upon success.
 */

int main(int ac, char **argv)
{
	char *line, **args;
	int status = 1, count = 0;

	(void)ac;

	signal(SIGINT, Sigint_handler);

	while (status)
	{

		++count;
		line = _readline();
		if (_strcmp(line, "\n") == 0)
		{
			free(line);
			continue;
		}
		args = split_line(line);
/*		if (args == NULL)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else

		free(line);
*/
		status = execute(argv, args, count);

		free_dbl_ptr(args);
	}

	return (0);
}

/**
 * Sigint_handler - handles Ctrl+C signals.
 * @sign: signal to handle.
 */

void Sigint_handler(int sign)
{
	(void)sign;
	write(STDOUT_FILENO, "\n$ ", 3);
}
