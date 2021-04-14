#include "holberton.h"

/**
 * _env - gets the value of an env variable.
 * @var: pointer to the env variable for the value.
 * @env: pointer to the array of pointers.
 * Return: pointer to the found value, or NULL if it fails.
 */

char *_env(char *var, char **env)
{
int i, length;
char *env_variable;

length = _strlen(var);
for (i = 0; env[i]; i++)
{
if (_strncmp(env[i], var, length) == 0)
{
env_variable = env[i];
break;
}
}
env_variable = _strtok(env_variable, "=");
free(env_variable);
env_variable = _strtok(NULL, "=");
return (env_variable);
}
