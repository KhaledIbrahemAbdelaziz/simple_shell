#include "shell.h"
#include <limits.h>

/**
 * cd - Changes the current working directory
 * @args: The dir to change to.
 * Return: -1 one success, 0 otherwise.
 */
int cd(char **args)
{
	char *dir, cwd[PATH_MAX];

	if (args[1] == NULL)
	{
		dir = getenv("HOME");
		if (dir == NULL)
		{
			fprintf(stderr, "No home directory found\n");
			return (0);
		}
	}
	else if (strcmp(args[1], "-") == 0)
	{
		dir = getenv("OLDPWD");
		if (dir == NULL)
		{
			fprintf(stderr, "cd: OLDPWD not set\n");
			return (0);
		}
		printf("%s\n", dir);
	}
	else
	{
		dir = args[1];
	}
	if (chdir(dir) != 0 || (getcwd(cwd, sizeof(cwd)) == NULL))
	{
		perror("cd");
		perror("getcwd");
		return (0);
	}
	if (setenv("OLDPWD", getenv("PWD"), 1) == -1 || (setenv("PWD", cwd, 1) == -1))
	{
		perror("setenv");
		perror("setenv");
		return (0);
	}
	return (-1);

}

