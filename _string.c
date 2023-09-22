#include "main.h"

/**
 * _strcmp - Compare two strings.
 * @str1: First string.
 * @str2: Second string.
 * Return: 1 if they're identical, 0 otherwise, -1 for error.
 */
int _strcmp(char *str1, char *str2)
{
	if (!str1 || !str2)
		return (-1); /* -1 for error */
	while (*str1 || *str2)
	{
		if (*str1++ != *str2++)
			return (0);
	}
	return (1);
}

/**
 * _strcmpn - Compare two strings up to a length.
 * @str1: First string.
 * @str2: Second string.
 * @len: Length to compare.
 * Return: 1 if they're identical up to length, 0 otherwise, -1 for error.
 */
int _strcmpn(char *str1, char *str2, int len)
{
	if (!str1 || !str2 || len <= 0)
		return (-1); /* -1 for error */
	while (*str1 || *str2)
	{
		if (len < 1)
			break;
		if (*str1++ != *str2++)
			return (0);
		len--;
	}
	return (1);
}

/**
 * _strcpy - Copy a string.
 * @str: String to copy.
 * Return: New string.
 */
char *_strcpy(char *str)
{
	int len = 0;
	char *new;

	while (str[len])
		len++;

	new = malloc((len + 1) * sizeof(char));
	new[len] = '\0';
	len--;

	while (len >= 0)
	{
		new[len] = str[len];
		len--;
	}
	return (new);
}

/**
 * _strcon - Concatenate two strings with a '/' in between.
 * @str1: First string.
 * @str2: Second string.
 * Return: New concatenated string.
 */
char *_strcon(char *str1, char *str2)
{
	char *new;
	int len1 = 0, len2 = 0, counter = 0;

	while (str1[len1])
		len1++;
	while (str2[len2])
		len2++;

	new = malloc((len1 + len2 + 2) * sizeof(char));
	while (counter < len1)
	{
		new[counter] = str1[counter];
		counter++;
	}
	new[counter] = '/';
	counter = 0;

	while (counter < len2)
	{
		new[len1 + counter + 1] = str2[counter];
		counter++;
	}
	new[len1 + counter + 1] = '\0';
	return (new);
}

/**
 * _intToStr - Convert an integer to a string.
 * @n: The integer.
 * Return: The converted string.
 */
char *_intToStr(int n)
{
	char arr[32];
	char *newStr;
	int i = 0, len, temp;

	while (n)
	{
		arr[i++] = 48 + n % 10;
		n /= 10;
	}

	newStr = malloc((i + 1) * sizeof(char));
	len = i - 1;
	temp = i;
	i = 0;

	while (i < temp)
	{
		newStr[i] = arr[len];
		i++;
		len--;
	}
	newStr[i] = '\0';
	return (newStr);
}
