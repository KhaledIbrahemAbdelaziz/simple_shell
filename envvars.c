#include "shell.h"

/**
 * env - prints enviroment variables
 * @args: arguments
 * Return: 1 on success, otherwise return 0
 */
int env(char **args)
{
	int i = 0;
	(void)(**args);

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (-1);
}

