#include "holberton.h"
#include <stdlib.h>

/**
 * _strlen - measure the length of a string.
 *
 * @s: the string to be measured.
 *
 * Return: the length of the string.
 */

int _strlen(char *s)
{
	int i, l;

	for (i = 0; s[i] != '\0'; i++)
		l++;
	return (l);
}

/**
 * _strcpy - copy a string from source to destination.
 *
 * @dest: the destination of the string to be copied to.
 * @src: the source of the string to be copied.
 *
 * Return: the pointer to the destination.
 */

char *_strcpy(char *dest, char *src)
{
	int i;
	char *buff = dest;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = src[i];
	return (buff);
}

/**
 * _strcmp - compares two strings.
 *
 * @s1: the first string.
 * @s2: the second string.
 *
 * Return: 0 if they are equal, positive if s2 is greater and negative if not.
 */

int _strcmp(char *s1, char *s2)
{

	int i, j;

	for (i = 0, j = 0; (s1[i] != '\0') && (s2[i] != '\0'); i++)
	{
		j = s1[i] - s2[i];
		if (j != 0)
			break;
	}
	return (j);
}

/**
 * _strdup - duplicates a string in memory.
 *
 *  @s: string to be duplicated.
 *
 * Return: duplicated string.
 */

char *_strdup(char *s)
{

	char *buff;
	unsigned int len;

	len = _strlen(s);
	buff = malloc(sizeof(char) * (len + 1));
	if (buff == NULL)
		return (NULL);
	_memcpy(buff, s, len + 1);
	return (buff);
}
