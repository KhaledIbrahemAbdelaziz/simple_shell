#include "shell.h"

/**
 * exits - Exits the shell.
 * @argv: The array of arguments.
 * @buf: The buffer of command lines.
 * Return: nothing to return.
 */

void exits(char *argv[], char *buf)
{
	if (!argv[1])
	{
		free(argv);
		free(buf);
		exit(98);
	}
	free(argv);
	free(buf);
	exit(98);
}

/**
 * Env - get the current environment.
 * @env: The current environment.
 * Return: nothing to return.
 */

void Env(char *env[])
{
	size_t i;

	while (env[i])
	{
		write(STDOUT_FILENO, env[i], strlength(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * strlength - calculate  The length of the string.
 * @str: The string.
 * Return: The length of the string.
 */

int strlength(char *str)
{
	int i, size = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		size++;
	}
	return (size);
}
