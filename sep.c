#include "shell.h"

/**
 * command_sep - executes a command seperated by ';'.
 * @args: the array of strings containing the cmds.
 * Return: The exit status of the last cmd executed.
 */
int command_sep(char **args)
{
	int status = 0;
	char *command = *args;

	while (command != NULL)
	{
		char *seperator = strchr(command, ';');

		if (seperator != NULL)
		{
			*seperator = '\0';
		}
		else
		{
			status = new_proc(parse_command(command));
		}

		if (seperator  != NULL)
		{
			*seperator = ';';
			command = &seperator[1];
		}
		else
		{
			break;
		}
	}
	return (status);
}

/**
 * new_proc - Launch a new process to execute a command
 * @args: An array of strings containing the command and its arguments
 *
 * Return: The exit status of the command executed
 */
int new_proc(char **args)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("hsh");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("hsh");
		status = -1;
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (status);
}

/**
 * parse_command - parse a command line into individual args.
 * @line: Is the command line to pass.
 * Return: An array of strings.
 */
char **parse_command(char *line)
{
	int bf_size = MAX_LINE / 2 + 1;
	int place = 0;
	char **tks = malloc(bf_size * sizeof(char *));
	char *tk;

	if (!tks)
	{
		fprintf(stderr, "hsh: Allocation error\n");
		exit(EXIT_FAILURE);
	}
	tk  = strtok(line, "\t\r\n\a");
	while (tk != NULL)
	{
		tks[place] = tk;
		place++;

		if (place >= bf_size)
		{
			bf_size += MAX_LINE / 2 + 1;
			tks = realloc(tks, bf_size * sizeof(char *));
		}
		if (!tks)
		{
			fprintf(stderr, "hsh: Allocation error\n");
			exit(EXIT_FAILURE);
		}
		tk = strtok(NULL, " \t\r\n\a");
	}
	tks[place] = NULL;
	return (tks);
}


