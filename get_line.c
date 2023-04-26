#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * get_line - reads a line of input from stdin.
 *
 * Return: a pointer to the line of input, or NULL if there is no more input.
 */
char *get_line(void)
{
	static char buffer[BUFFER_SIZE];
	static int point = 0, len = 0;
	char *line = NULL, c = buffer[point++];
	int i = 0;

	line = malloc(BUFFER_SIZE);
	if (point >= len || line == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		if (point >= len)
		{
			point = 0;
			len = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			if (len == -1)
			{
				perror("read");
				exit(EXIT_FAILURE);
			}
			else if (len == 0)
			{
				printf("Error: End of input\n");
				exit(EXIT_FAILURE);
			}
		}

		line[i++] = c;
		if (c == '\n' || i >= BUFFER_SIZE)
		{
			line[i] = '\0';
			return (line);
		}
	}
}


