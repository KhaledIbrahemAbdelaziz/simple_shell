#include "shell.h"

/**
 * command_mode - returns true if shell is user interactive mode
 * @data: pointer to struct addr
 * Return: 1 if user interactive mode, therwise return 0
 */
int command_mode(data_r *data)
{
	return (isatty(STDIN_FILENO) && data->runfd <= 2);
}

/**
 * checker - runs to see if its is the delimiter
 * @i: the char to check
 * @delimiter: delimeter string
 * Return: 1 if true, otherwise 0 if false
 */
int checker(char i, char *delimiter)
{
	while (*delimiter)
		if (*delimiter++ == i)
		{
			return (1);
		}
	return (0);
}

/**
 * character - searches for alphabets
 * @i: is the input character
 * Return: 1 if i is alphabetic, otherwise return 0
 */

int character(int i)
{
	if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * converter - a function that converts a string to an integer
 *@string: the string to be converted
 *Return: 0 if zero nums on string, otherwise converted number
 */

int converter(char *string)
{
	int j, label = 1;
	int err = 0;
	int prod;
	unsigned int yield = 0;

	for (j = 0;  string[j] != '\0' && err != 2; j++)
	{
		if (string[j] == '-')
			label *= -1;

		if (string[j] >= '0' && string[j] <= '9')
		{
			err = 1;
			yield *= 10;
			yield += (string[j] - '0');
		}
		else if (err == 1)
			err = 2;
	}

	if (label == -1)
		prod = -yield;
	else
		prod = yield;

	return (prod);
}

