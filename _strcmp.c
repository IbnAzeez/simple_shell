#include "shell.h"

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string to compare to first string
 * Return: <0 if s1 is less than s2, 0 for equal, >0 if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

