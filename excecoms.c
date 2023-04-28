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
		"setenv",
		"unsetenv",
		"exit"
	};
	int (*builtin_func[])(char **) = {
		&cd,
		&env,
		&help,
		&set_env,
		&unset_env,
		&my_exit
	};
	unsigned long int j = 0;

	if (args[0] == NULL)
	{
		return (-1);
	}
	for (; j < sizeof(builtin_func_list) / sizeof(char *); j++)
	{
		if (strcmp(args[0], builtin_func_list[j]) == 0)
		{
			return ((*builtin_func[j])(args));
		}
	}
	return (forks(args));
}
