#include "shell.h"

/**
 * main - function that checks if our shell is called
 * Return: 0 on success
 */
int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		user_interactive();
	}
	else
	{
		tok_en();
	}
	return (0);
}

