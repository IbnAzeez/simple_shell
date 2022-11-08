#include "shell.h"

/**
 * _strn_cmp - compares n chars from two strings
 * @s1: first string
 * @s2: second string to compare to first string
 * @n: no of the comparison between s1 and s2
 * Return: <0 if s1 is less than s2, 0 for equal, >0 if s1 is greater than s2
 */
int _strn_cmp(char *s1, char *s2, int n)
{
	char c1, c2;

	while (n--)
	{
		c1 = *s1++;
		c2 = *s2++;
		if (c1 == '\0' || c1 != c2)
			return (c1 > c2 ? 1 : (c1 < c2 ? -1 : 0));
	}
	return (0);
}
