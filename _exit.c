#include "main.h"

extern int child_exit_status;

/**
 * _isInt - Checks if a string is an integer.
 * @s: The string to check.
 * Return: 1 if integer, 0 otherwise.
 */
int _isInt(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
		i++;
	}
	if (!i)
		return (0);
	return (1);
}

/**
 * _strToInt - Converts string to integer.
 * @str: The string to convert.
 * Return: The integer.
 */
int _strToInt(char *str)
{
	int num = 0, i = 0;

	while (str[i])
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num);
}

/**
 * _exitFromShell - Exits from the shell.
 * @args: Arguments.
 * @line: Line input.
 * @argv: Argument vector.
 */
void _exitFromShell(char **args, char *line, char *argv[])
{
	int exitStatus;

	if (!args[1])
	{
		free(args);
		free(line);
		exit(child_exit_status);
	}
	else
	{
		/* If the exit status code is specified */
		if (_isInt(args[1]))
		{
			exitStatus = _strToInt(args[1]);
			free(args);
			free(line);
			exit(exitStatus);
		}
		else
		{
			_perror(4, argv[0], ": exit: Illegal number:", args[1], "\n");
			return;
		}
	}
}

