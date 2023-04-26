#include "shell.h"

/**
 * cd_dir - gets the target directory for the cd command.
 *
 * @args: an array of strings containing the command and its arguments.
 *
 * Return: a string containing the target directory,
 * or NULL if an error occurs.
 */
static char *cd_dir(char **args)
{
	char *dir;

	if (args[1] == NULL)
	{
		dir = getenv("HOME");
		if (dir == NULL)
		{
			fprintf(stderr, "cd: HOME not set\n");
			return (NULL);
		}
	}
	else if (strcmp(args[1], "-") == 0)
	{
		dir = getenv("OLDPWD");
		if (dir == NULL)
		{
			fprintf(stderr, "cd: OLDPWD not set\n");
			return (NULL);
		}
		printf("%s\n", dir);
	}
	else
	{
		dir = args[1];
	}
	return (dir);
}

/**
 * change_dir - changes the current directory of the process.
 *
 * @dir: a string containing the target directory.
 *
 * Return: 0 on success, or -1 if an error occurs.
 */
static int change_dir(char *dir)
{
	if (chdir(dir) != 0)
	{
		fprintf(stderr, "cd: %s: %s\n", dir, strerror(errno));
		return (-1);
	}
	return (0);
}

/**
 * update_cd - updates the PWD and OLDPWD environment variables.
 *
 * Return: 0 on success, or -1 if an error occurs.
 */
static int update_cd(void)
{
	char cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		fprintf(stderr, "cd: %s\n", strerror(errno));
		return (-1);
	}
	if (setenv("OLDPWD", getenv("PWD"), 1) != 0)
	{
		fprintf(stderr, "cd: failed to set OLDPWD\n");
		return (-1);
	}
	if (setenv("PWD", cwd, 1) != 0)
	{
		fprintf(stderr, "cd: failed to set PWD\n");
		return (-1);
	}
	return (0);
}

/**
 * my_cd - changes the current directory of the process.
 *
 * @args: an array of strings containing the command and its arguments.
 * @env: the environment variables.
 */
void my_cd(char **args, char **env __attribute__((unused)))
{
	char *dir;

	dir = cd_dir(args);
	if (dir == NULL)
	{
		return;
	}
	if (change_dir(dir) != 0)
	{
		return;
	}
	if (update_cd() != 0)
		return;
}

