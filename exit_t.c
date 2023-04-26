#include "shell.h"

/**
 * exit_now - exits the shell with the specisfied status.
 * @arg: is the exit status as a stirng, or NULL for the,
 * default status.
 */
void exit_now(char *arg)
{
	int status = 0;

	if (arg != NULL)
	{
		status = atoi(arg);
	}
	exit(status);
}

/**
 * entry - the entry point for the program.
 * Return: 0 on success, otherwise a non-zero value.
 */
char *entry(void)
{
	char *line;

	while (1)
	{
		printf("$ ");
		line = entry();

		if (line == NULL)
		{
			break;
		}
		if (strcmp(line, "exit") == 0)
		{
			exit_now(NULL);
		}
		else if (strncmp(line, "exit", 5) == 0)
		{
			exit_now(line + 5);
		}
		free(line);
	}
	return (0);
}
