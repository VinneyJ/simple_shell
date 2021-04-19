#include "holberton.h"
#include <stdio.h>
#include <unistd.h>

/**
 * execute - executes a shell program.
 * @argv: the argument vector from main function.
 * @comm: the commands string vector.
 * @count: the number of times a command is executed.
 * Return: the status of the execution.
 */

int execute(char **argv, char **comm, int count)
{
	pid_t child_pid;
	int status, i;
	struct stat filestat, filestat2;
	char *exit_com = "exit", *env_com = "env", **all_dir;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (_strcmp(exit_com, comm[0]) == 0)
			shell_exit(comm);
		else if (_strcmp(env_com, comm[0]) == 0)
			_env(environ);
		else if (stat(comm[0], &filestat) == 0)
			execve(comm[0], comm, NULL);
		else
		{
			all_dir = store_path_command(comm[0]);
			for (i = 0; all_dir[i] != NULL; i++)
				if (stat(all_dir[i], &filestat2) == 0)
					execve(all_dir[i], comm, NULL);
			error_mess(argv, comm, count);
			free_dbl_ptr(all_dir);
			exit(EXIT_SUCCESS);
		}
	}
	else
	{
		wait(&status);
		if (comm == NULL)
			free_dbl_ptr(comm);
		else if (_strcmp(exit_com, comm[0]) == 0)
			shell_exit(comm);
	}
	return (1);
}
