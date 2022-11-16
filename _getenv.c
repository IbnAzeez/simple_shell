#include "shell.h"

/**
 * _getenv - get environment variable
 * @node: first node
 * @env_name: environment variable name
 * Return: environment variable node
 */
environment_t *_getenv(environment_t *node, char *env_name)
{
	if (node == NULL)
		return (NULL);

	if (_strcmp(node->name, env_name) == 0)
		return (node);

	return (_getenv(node->next, env_name));
}
