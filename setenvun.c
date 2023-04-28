#include "shell.h"

/**
 * set_env - Initializes a new environment
 * @args: THe var and val to set
 * Return: -1 on success, 0 otherwise
 */
int set_env(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		fprintf(stderr, "setenv: invalid arguments\n");
		return (0);
	}
	if (setenv(args[1], args[2], 1)  == -1)
	{
		perror("setenv");
		return (0);
	}
	return (-1);
}

/**
 * unset_env - Remove an env var
 * @args: THe var to remove
 * Return: -1 on success, otherwise 0
 */
int unset_env(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "unsetenv: Invalid argument\n");
		return (0);
	}
	if (unsetenv(args[1]) == -1)
	{
		perror("unsetenv");
		return (0);
	}
	return (-1);
}

