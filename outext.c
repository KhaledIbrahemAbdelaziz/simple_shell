#include "shell.h"

/**
 *my_exit - exits the Normal process
 * @args: number of arguments(not-present)
 * Return: Always 0
 */
int my_exit(char **args)
{
	if (args[1])
	{
		return (atoi(args[1]));
	}
	else
	{
		return (0);
	}
}

