#include "shell.h"

/**
 * user_interactive - this function enables users to interact
 * Return: Nothing
 */
void user_interactive(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		printf("Lab_shell$ ");
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

