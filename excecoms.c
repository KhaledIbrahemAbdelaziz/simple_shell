#include "shell.h"

/**
 * run_coms - Tells if command is a builtin or a process
 * @args: command and its flags
 * Return: 1 on success, otherwise 0 on failure
 */
int run_coms(char **args)
{
	char *builtin_func_list[] = {
		"cd",
		"env",
		"help",
		"exit"
	};
	int (*builtin_func[])(char **) = {
		&cd,
		&env,
		&help,
		&my_exit
	};
	long unsigned int i = 0;

	if (args[0] == NULL)
	{
		return (-1);
	}
	for (; i < sizeof(builtin_func_list) / sizeof(char *); i++)
	{
		if (strcmp(args[0], builtin_func_list[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}
	return (forks(args));
}
