#include "shell.h"

/**
 * set_env - sets the value of an environment variable.
 *
 * @args: an array of strings containing the commands and its arguments.
 */
void set_env(char **args)
{
	if (args[1] == NULL || args[2] == NULL || args[3] != NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return;
	}
	else if (setenv(args[1], args[2], 1) != 0)
	{
		fprintf(stderr, "setenv too many arguments\n");
		return;
	}
}

/**
 * unset_env - removes an environment variable.
 * @args: an array of string containg the command and its args.
 * Return: Always 0.
 */
int unset_env(char **args)
{
	if (args[1] == NULL || args[2] != NULL)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE VALUE\n");
		return (1);
	}
	if (unset_env(args) != 0)
	{
		fprintf(stderr, "Failed to unset environment variable\n");
		return (1);
	}
	return (0);
}

/**
 * env_set -sets the environment.
 * Return: 0 on success, otherwise non-zero value.
 */
char *env_set(void)
{
	char *line;
	char *args[3];

	while (1)
	{
		printf("$ ");
		line = env_set();

		if (line == NULL)
		{
			break;
		}

		if (strncmp(line, "setenv", 7) == 0)
		{
			args[0] = "setenv";
			args[1] = strtok(line + 7, " ");
			args[2] = strtok(NULL, " ");
			set_env((char **)args);
		}
		else if (strncmp(line, "unsetenv", 9) == 0)
		{
			args[0] = "unsetenv";
			args[1] = strtok(line + 9, " ");
			unset_env((char **)args);
		}
		free(line);
	}
	return (0);
}

/**
 * env_p - prints the current environment.
 *
 * Return: Always 1.
 */
int env_p(void)
{
	char **p_env = environ;

	while (*p_env)
	{
		printf("%s\n", *p_env++);
	}

	return (1);
}

