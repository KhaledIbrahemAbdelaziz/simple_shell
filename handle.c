#include "shell.h"

/**
 * help - this function prints help
 * @args: arguments
 * Return: 1 on success, otherwise return 0
 */
int help(char **args)
{
	char *builtin_func_list[] = {
		"cd",
		"env",
		"help",
		"setenv",
		"unsetenv",
		"exit"
	};
	unsigned long int i = 0;
	(void)(**args);

	printf("\n---help---\n");
	printf("Enter an command and hit the return button\n");
	printf("This are the Builtin commands:\n");
	for (; i < sizeof(builtin_func_list) / sizeof(char *); i++)
	{
		printf("  -> %s\n", builtin_func_list[i]);
	}
	printf("Run man(command) to know more info about other programs\n\n");
	return (-1);
}

