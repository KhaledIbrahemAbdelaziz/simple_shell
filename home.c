#include "shell.h"

/**
 * cd - Changes the current working directory
 * @args: The dir to change to.
 * Return: 1 one success, 0 otherwise.
 */
int cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "Expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("%s:Error: no such file or directory\n");
		}
	}
	return (1);
}

