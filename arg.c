#include "shell.h"

/**
 * num_args - counts the number of commandline strings.
 * @str: an array of strings.
 * Return: the number of strings.
 */
int num_args(char *str)
{
	int count = 0;

	char *token = strtok(str, " ");

	while (token != NULL)
	{
		count++;
		token = strtok(NULL, " ");
	}

	return (count);
}

/**
 * convert_str - converts argumnet string to integer.
 * @str: an array of strings.
 *
 * Return: result * sign
 */
int convert_str(char *str)
{
	int num = 0;

	while (*str != '\0')
	{
		num = num * 10 + (*str - '0');
		str++;
	}

	return (num);
}

