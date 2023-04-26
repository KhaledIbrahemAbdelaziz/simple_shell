#include "shell.h"

/**
 * tk_command - tokenizes a command into arguments.
 * @command: the command to tokenize.
 * @args: an array to store the arguments.
 *
 * Return: the number of arguments.
 */
int tk_command(char *command, char **args)
{
	int i = 0;
	char *token = strtok(command, " ");

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}

	args[i] = NULL;

	return (i);
}

/**
 * my_builtin_command - checks if a command is a built-in command.
 * @command: the command to check.
 *
 * Return: 1 if the command is a built-in command, 0 otherwise.
 */
int my_builtin_command(char *command)
{
	return (strcmp(command, "cd") == 0 || strcmp(command, "exit") == 0);
}

/**
 * execute_builtin_command - executes a built-in command.
 * @args: the arguments for the command.
 * @buf: the pinter to buffer.
 * Return: 0 on success, -1 on failure.
 */
int execute_builtin_command(char **args, char *buf)
{
	exits(args, buf);

	if (strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
		{
			printf("Error: Missing argumentfor cd command\n");
			return (-1);
		}

		else if (chdir(args[1]) == -1)
		{
			printf("Error: Failed to change directory\n");
			return (-1);
		}
	}
	else if (strcmp(args[0], "exit") == 0)
	{
		exits(args, buf);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		Env(args);
	}

	return (0);
}

/**
 * execute_external_command - executes an external command.
 * @args: the arguments for the command.
 *
 * Return: 0 on success, -1 on failure.
 */
int execute_external_command(char **args)
{
	pid_t pid = -1;
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");
	char command_path[MAX_COMMAND_LENGTH];

	while (dir != NULL)
	{
		snprintf(command_path, MAX_COMMAND_LENGTH, "%s/%s", dir, args[0]);
		if (access(command_path, X_OK) == 0)
		{
			args[0] = command_path;
			break;
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	if (dir == NULL || pid == -1)
	{
		printf("Error: Command not found\n");
		printf("Error: Failed to fork child process\n");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execv(args[0], args) == -1)
		{
			printf("Error: Failed to execute command\n");
			exit(1);
		}
	}
	else
	{
		if (wait(NULL) == -1)
		{
			printf("Error: Failed to wait for child process\n");
			return (-1);
		}
	}
	return (0);
}

/**
 * execute_cmd - executes a command in a child process.
 * @command: the command to execute.
 *
 * Return: 0 on success, -1 on failure.
 */
int execute_cmd(char *command)
{
	char *args[MAX_COMMAND_LENGTH] = {NULL};
	int num_args = tk_command(command, args);
	char buf[MAX_COMMAND_LENGTH];

	if (num_args == 0)
	{
		return (0);
	}

	if (my_builtin_command(args[0]))
	{
		return (execute_builtin_command(args, buf));
	}

	else
	{
		return (execute_external_command(args));
	}
}

