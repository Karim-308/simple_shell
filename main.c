#include "main.h"

extern char **environ;
int child_exit_status = 0;  /* To capture child process exit status */

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to write.
 * Return: On success 1, on error -1.
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/**
 * printEnv - Prints the environment variables.
 */
void printEnv(void)
{
	int i, j;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j]; j++)
			_putchar(environ[i][j]);
		_putchar('\n');
	}
}

/**
 * split_line - Splits a line into tokens.
 * @line: The line to split.
 * @bufsize: Size of the buffer.
 * Return: Tokens.
 */
char **split_line(char *line, int bufsize)
{
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token;

	if (!tokens)
	{
		perror("simple_shell: allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;

	if (position == 0)
	{
		free(tokens);
		return NULL;
	}
	return tokens;
}

/**
 * _getenv - Get an environment variable.
 * @name: Name of the environment variable.
 * @length: Length of the name.
 * Return: Value of the environment variable.
 */
char *_getenv(char *name, int length)
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
 * isCommand - Checks if a string is a command.
 * @com: The string to check.
 * Return: The command.
 */
char *isCommand(char *com)
{
	struct stat buffer;
	char *dir = NULL;
	char *PATH = NULL;
	char *PATHcpy = NULL;
	char *filePath = NULL;
	char *returnPath = NULL;
	char delimiters[] = ":";

	if (com[0] == '/')
	{
		if (stat(com, &buffer) == 0)
			if (S_ISREG(buffer.st_mode))
				return (com);
			else
				return (NULL);
		else
			return (NULL);
	}
	PATH = _getenv("PATH", 4);
	PATHcpy = _strcpy(PATH);
	dir = strtok(PATHcpy, delimiters);
	while (dir)
	{
		filePath = _strcon(dir, com);
		if (stat(filePath, &buffer) == 0)
		{
			returnPath = _strcpy(filePath);
			free(filePath);
			free(PATHcpy);
			return (returnPath);
		}
		free(filePath);
		dir = strtok(NULL, delimiters);
	}
	free(PATHcpy);
	return NULL;
}


/**
 * main - Entry point.
 * @argc: Argument count.
 * @argv: Argument vector.
 * @envp: Environment variables.
 * Return: Exit status.
 */
int main(int argc, __attribute__((unused))char *argv[], __attribute__((unused))char *envp[])
{
	ssize_t bytes;
	char *line = NULL;
	size_t length;
	pid_t pid;
	char *command = NULL, *commNumStr = NULL;
	int interactive = isatty(STDIN_FILENO), commNum = 0;
	char **args = NULL;
	int status;

	if (argc != 1)
	{
		perror("Usage: ./shell\n");
		return (EXIT_FAILURE);
	}

	while (1)
	{
		commNum++;
		if (interactive)
			write(STDOUT_FILENO, "($) ", 5);

		bytes = getline(&line, &length, stdin);
		if (bytes == -1)
		{
			if (!interactive)
				break;
			_putchar('\n');
			break;
		}
		else if (bytes == 1)
		{
			continue;
		}
		else
		{
			args = split_line(line, bytes);

			if (!args) /*if spaces are entered*/
				continue;

			if (_strcmp(args[0], "exit"))
			{
				_exitFromShell(args, line, argv);
				free(args);
				continue;
			}

			if (_strcmp(args[0], "env"))
			{
				free(args);
				printEnv();
				continue;
			}

			command = isCommand(args[0]);
			if (command)
			{
				pid = fork();
				if (pid < 0)
				{
					_perror(1, "Failed to fork\n");
					continue;
				}
				else if (pid == 0)
				{
					if (execve(command, args, environ) == -1)
					{
						commNumStr = _intToStr(commNum);
						_perror(6, argv[0], ": ", commNumStr, ": ", args[0], ": " "not found\n");
						free(commNumStr);
						exit(127);  /* Exit with an error code when command not found */
					}
				}
				else
				{
					wait(&status);  /* Capture the status */
					if (WIFEXITED(status))
					{
						child_exit_status = WEXITSTATUS(status);
					}
				}
			}
			else
			{
				commNumStr = _intToStr(commNum);
				_perror(6, argv[0], ": ", commNumStr, ": ", args[0], ": " "not found\n");
				free(commNumStr);
				child_exit_status = 127;  /* Set error code when command not found */
			}

			if (command != args[0])
				free(command);
			if (args != NULL)
				free(args);
		}
	}

	if (line != NULL)
		free(line);

	return child_exit_status;  /* Return the captured child exit status */
}

