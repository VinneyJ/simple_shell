#include "holberton.h"

/**
 * _strcat - concatenate two strings.
 *
 * @dest: the destination.
 * @src: the source.
 *
 * Return: the pointer to the resulting string.
 */
char *_strcat(char *dest, char *src)
{
	int i, j, k, l;
	char *buff = dest;

	for (i = 0; dest[i] != '\0'; i++)
		l++;
	for (j = l, k = 0; src[k] != '\0'; j++, k++)
		dest[j] = src[k];
	dest[j] = '\0';
	return (buff);
}
