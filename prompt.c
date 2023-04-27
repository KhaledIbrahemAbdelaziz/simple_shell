#include "shell.h"

int check_mode(void);

/**
 * check_mode - check if the shell in interactive mode or not.
 * Return: 1 if interactive or 0 otherwise.
 */

int check_mode(void)
{
	return (isatty(STDIN_FILENO) <= 2);
}
/**
 * prompt - prints the prompt.
 * @argv: pointer to arguments.
 * @env: pointer to the env variables.
 */

void prompt(char *argv[], char *env[])
{
	char *buffer = NULL, *token[1024] = {NULL};
	size_t size = 0;
	ssize_t command;
	int stat, y, x;
	pid_t proc_child;

	while (1)
	{
		if (check_mode())
			printf("#cisfun$ ");
		command = getline(&buffer, &size, stdin);
		if (command == -1)
		{
			free(buffer);
			exit(98);
		}
		y = 0;
		while (buffer[y])
		{
			if (buffer[y] == '\n')
				buffer[y] = 0;
			y++;
		}
		x = 0;
		token[x] = strtok(buffer, " ");
		while (token[x] && x < 1023)
			token[++x] = strtok(NULL, " ");
		proc_child = fork();
		if (proc_child == -1)
		{
			free(buffer);
			exit(98);
		}
		if (proc_child == 0)
		{
			if (x > 1)
			{
				if (execvp(token[0], token) == -1)
					printf("%s: Command not found", token[0]);
			}
			else if (strcompare(token[0], "exit") == 0)
				exits(argv, buffer);
			else if (strcompare(token[0], "env") == 0)
				Env(env);
			else
			{
				if (execvp(token[0], token) == -1)
					printf("%s: Command not found\n", token[0]);
			}
			free(buffer);
			exit(0);
		}
		else
			wait(&stat);
	}
}

/**
 * strcompare - compare between two strings.
 * @str1: first string.
 * @str2: second string.
 * Return: 0 if equal and diff otherwise.
 */

int strcompare(char *str1, char *str2)
{
	if (str1 == NULL || str2 == NULL)
	{
		return (1);
	}
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
	}
	if (*str1 != *str2)
	{
		return (*str1 - *str2);
	}
	return (0);
}

