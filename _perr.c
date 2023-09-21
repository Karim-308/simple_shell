#include "main.h"

/**
 * _perror - Custom perror function.
 * @n: Number of arguments.
 * Return: void.
 */
void _perror(int n, ...)
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
	write(STDERR_FILENO, &buffer, len);
}

