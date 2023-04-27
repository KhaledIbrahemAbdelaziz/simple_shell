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
	char *buffer, *token[] = {NULL, NULL};
	size_t size;
	ssize_t command;
	int stat, y, x;
	pid_t proc_child;

	while (1)
	{
		if (check_mode())
			printf("#cisfun$ ");
		buffer = malloc(sizeof(char *) * size);
		command = getline(&buffer, &size, stdin);
		if (command == -1)
		{
			free(buffer);
			exit(EXIT_FAILURE);
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
		while (token[x])
			token[++x] = strtok(NULL, " ");
		proc_child = fork();
		if (proc_child == -1)
		{
			free(buffer);
			exit(EXIT_FAILURE);
		}
		if (proc_child == 0)
		{
			if (x > 1)
			{
				if (execve(token[0], token, env) == -1)
					printf("%s: No such file or directory\n", argv[0]);
			}
			else
			{
				if (execve(token[0], token, env) == -1)
					printf("%s: No such file or directory\n", argv[0]);
			}
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
	int i;

	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
			return ((int)str1[i] - str2[i]);
	}
	return (0);
}
