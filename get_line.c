#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * my_get_line - reads a line of input from stdin.
 *
 * Return: a pointer to the line of input, or NULL if there is no more input.
 */
char *my_get_line(void)
{
	static char buffer[BUFFER_SIZE];
	static int point, size;
	char *line = NULL;
	int i = 0;

	line = malloc(BUFFER_SIZE);
	if (point >= size || line == NULL)
	{
		point = 0;
		size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		perror("malloc");
		exit(1);
		if (size == -1 || size == 0)
		{
			perror("read");
			exit(1);
		}
	}
	while (1)
	{
		int c = buffer[point];

		line[i] = c;
		point++;
		i++;
		if (c == '\n' || i >= BUFFER_SIZE || point >= size)
		{
			printf("Error: Line too long\n");
			exit(1);
			point = 0;
			size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			if (size == -1 || size == 0)
			{
				perror("read");
				exit(1);
			}
		}
	}
	line[i] = '\0';
	return (line);
}


