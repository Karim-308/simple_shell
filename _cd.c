#include "main.h"

/**
 * _getenv2 - Get an environment variable.
 * @name: Name of the environment variable.
 * @length: Length of the name.
 * Return: Value of the environment variable.
 */
char *_getenv2(char *name, int length)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		if (_strcmpn(environ[i], name, length))
			return (environ[i] + length + 1);
	}
	return (NULL);
}

/**
 * copy - copies from loc to another
 * @to: to string
 * @from: from string
 * Return: nothing
 */
void copy(char (*to)[128], char (*from)[128])
{
	int i = 0;

	while ((*from)[i])
	{
		(*to)[i] = (*from)[i];
		i++;
	}
	(*to)[i] = '\0';
}

/**
 * _puts - Custom puts function.
 * @n: Number of arguments.
 * Return: void.
 */
void _puts(int n, ...)
{
	va_list ap;
	int i, j, len = 0;
	char buffer[1024], *temp;

	va_start(ap, n);
	for (i = 0; i < n; i++)
	{
		temp = va_arg(ap, char *);
		j = 0;
		while (temp[j])
		{
			buffer[len + j] = temp[j];
			j++;
		}
		len += j;
	}
	/*buffer[++len] = '\0';*/
	write(STDOUT_FILENO, &buffer, len);
}

/**
 * _cd - change dir
 * @args: args array
 * @line: command line
 * @argv: argv of the shell
 * @commNum: command line number
 * Return: nothing
 */
void _cd(char **args, __attribute__((unused)) char *line,
		__attribute__((unused)) char *argv[], char *commNum)
{
	char home[128], *homeTemp = _getenv2("HOME", 4);
	static char prev[128], curr[128], temp[128];
	int i = 0;

	if (_strToInt(commNum) == 1)
	{
		getcwd(prev, 128);
		getcwd(curr, 128);
		getcwd(temp, 128);
		for (i = 0; homeTemp[i]; i++)
			home[i] = homeTemp[i];
		home[i] = '\0';
	}
	getcwd(curr, 128);
	if (!args[1])
	{
		chdir(home);
		copy(&prev, &curr);
		copy(&curr, &home);
		return;
	}
	if (args[1][0] == '-' && !args[1][1])
	{
		copy(&temp, &prev);
		copy(&prev, &curr);
		copy(&curr, &temp);
		chdir(curr);
		_puts(2, curr, "\n");
		return;
	}
	copy(&temp, &prev);
	copy(&prev, &curr);
	if (chdir(args[1]) != 0)
	{
		copy(&prev, &temp);
		_perror(6, argv[0], ": ", commNum,
				": cd: can't cd to ", args[1], "\n");
		return;
	}
	getcwd(curr, 128);
}
