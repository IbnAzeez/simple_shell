#include "shell.h"

/**
 * _getenv - prints environment
 * @variable: environ variable
 *
 * Return: 0
 */

char *_getenv(char *variable)
{
	int i = 0;

	for (i = 0; environ[i]; i++)
	{
		if (_strn_cmp(environ[i], variable, _strlen(variable)) == 0)
			return (&environ[i][_strlen(variable)]);
	}
	return (NULL);
}
