#include "holberton.h"

/**
 * _strncmp - compares n bytes of string s2 with s1
 * @s1: first string to be compared
 * @s2: second string to be compared
 * @n: number of bytes to compare
 *
 * Return: 0 if s1 and s2 are the same,
 */

int _strncmp(char *s1, char *s2, int n)
{
  int remv, c;

  remv = 0;
  c = 0;
  while (c < n && s2[c])
    {
      if (s1[c] != s2[c])
	{
	  remv = s1[c] - s2[c];
	  break;
	}
      c++;
    }

  return (remv);
}
