#include "shell.h"

/**
 * hist - tells if the command is a history or not
 * @line: pointer to the user input.
 * Return: 0 on success, otherwie 1 on failure.
 */
int hist(char *line)
{
	const char *index = "history";
	int j;

	if (strlen(line) < strlen(index))
	{
		return (0);
	}
	for (j = 0; j < (int) strlen(index); j++)
	{
		if (line[j] != index[j])
			return (0);
	}
	return (1);
}

/**
 * present - checks if the command is in history.
 * @line: pointer to user input.
 * Return: 0 on success, otherwise 1 on failure.
 */
int present(char *line)
{
	int num = (int) strlen(line);
	int j;

	for (j = 0; j < num; j++)
	{
		if (!isspace(line[1]))
			return (0);
	}
	return (1);
}

