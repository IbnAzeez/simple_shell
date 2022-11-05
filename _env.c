#include "shell.h"
/**
 * _env - prints current environment
 * Return: 0
 */
int _env(void)
{
	char *str;
	int i;

	str = environ[0];

	i = 0;

	while (str)
	{
		write(1, str, _strlen(str));
		write(1, "\n", 1);
		str = environ[++i];
	}
	return (0);
}
