#include "shell.h"

/**
 * read_input - reads input from the user
 * Return: THe pointer to the string
 */
char *read_input(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			perror("Error: Invalid input in stdin");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}

