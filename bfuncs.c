#include "shell.h"

/**
 * execute_builtin - executes a command in a child process.
 * @args: the arguments for the command.
 *
 * Return: 0 on success, -1 on failure.
 */
int run_builtin(char **args)
{
	int result = 0;

	if (strcmp(args[0], "cd") == 0)
	{
		if ((args[1]) == NULL)
		{
			printf("Error: Missing argument for cd command\n");
			result = -1;
		}
	}
	else if (chdir(args[1]) == -1)
	{
		printf("Error; Missing arguments for cd command\n");
		result = -1;
	}

	else if (strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}

	else
	{
		printf("Error: unknown command\n");
		result = -1;
	}

	return (result);
}

/**
 * execute_command - executes a command in a child process.
 * @command: teh command to execute.
 *
 * Return: 0 on success, -1 on failure.
 */
int run_command(char *command)
{
	char *args[MAX_COMMAND_LENGTH] = {NULL};
	int i = 0;
	int result = 0;

	char *token = strtok(command, " ");

	while (token != NULL)
	{
		args[i] = token;
		token =  strtok(NULL, " ");
		i++;
	}

	args[i] = NULL;
	if  (strcmp(args[0], "ls") == 0 && strcmp(args[1], "-l") == 0)
	{
		args[1] = NULL;
	}
	if (run_builtin(args) == -1)
		result = -1;

	else
	{
		if (fork() == 0 || execvp(args[0], args) == -1)
		{
			printf("Error: command not found\n");
			exit(1);
		}
		else
		{
			if (wait(NULL) == -1)
			{
				printf("Error: Failed to wait for child process\n");
				result = -1;
			}
		}
	}

	return (result);
}

/**
 * main_entry - Entry point for the shell program.
 *
 * Return: Always 0.
 */
int main_entry(void)
{
	char command[MAX_COMMAND_LENGTH];
	int result;

	while (1)
	{
		printf("shell$ ");
		fflush(stdout);

		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			printf("\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		result = run_command(command);
		if (result == -1)
		{
			printf("Error: Failed to execute command\n");
		}
	}

	return (0);
}

