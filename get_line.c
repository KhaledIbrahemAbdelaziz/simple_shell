#include "shell.h"

/**
 * get_line - gets the user input.
 * Return: a pointer to the user input.
 */
char *get_line(void)
{
	int j = 0;
	int buff_size = 1024;
	char *line = malloc(buff_size * sizeof(char));
	char wan;

	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failure\n");
		exit(EXIT_FAILURE);
	}
	while ((wan = getchar()) != '\n')
	{
		if (wan == EOF)
		{
			free(line);
			return (NULL);
		}
		if (j >= buff_size)
		{
			buff_size = 2 * buff_size;
			line = realloc(line, buff_size);
		}
		line[j++] = wan;
	}
	line[j] = '\0';
	return (line);
}


