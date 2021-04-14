#include "holberton.h"
#include <stdio.h>
#include <unistd.h>

/**
 * execute - executes a shell program.
 * @args: the array of the shell to be executed.
 * Return: the status of the execution.
 */

int execute(char **args)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		return (1);
	}
	if (child_pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
			perror("Error");
		exit(EXIT_FAILURE);
	}
	else
		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	return (1);
}
