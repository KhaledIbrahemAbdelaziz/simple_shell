#include "shell.h"

/**
 * tok_en - This is a function that enables a non-interactive
 * user experience, non-interactive
 * Return: Nothing
 */
void tok_en(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		line = read_input();
		args = lines_sp(line);
		status = run_coms(args);
		free(line);
		free(args);
		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}

