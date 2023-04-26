#include "shell.h"

/**
 * main - UNIX command line interpreter
 * @argc: The number of arguments.
 * @argv: The array of arguments.
 * @env: The current environment.
 * Return: 0 in Success.
 */

int main(int argc, char *argv[], char *env[])
{
	if (argc == 1)
		prompt(argv, env);

	return (0);
}
