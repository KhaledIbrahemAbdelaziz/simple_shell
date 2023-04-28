#include "shell.h"

/**
 * forks - Function that creates a new process
 * @args: Array of strings that contains the command
 * Return: 1 if success, otherwise 0
 */
int forks(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid ==  0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("error in forks: child process");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("error in forks: forking");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (-1);
}

