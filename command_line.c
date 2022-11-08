#include "shell.h"

/**
 * command_line - handles command line
 * @s: string
 * @file_stream: getline input
 * Return: 0
 */
int command_line(char *s, size_t __attribute__((unused))file_stream)
{
	char *token;
	char *command_array[100];
	int i;

	token = NULL;

	if (_strcmp(s, "exit") == 0)
		return (2);
	if (_strcmp(s, "env") == 0)
		return (_printenv());
	token = strtok(s, " "), i = 0;

	while (token)
	{
		command_array[i++] = token;
		token = strtok(NULL, " ");
	}
	command_array[i] = NULL;
	return (_command(command_array));
}
