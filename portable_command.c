#include "shell.h"

/**
 * _command - command call
 *
 * @command_array: a string provided by the stdin
 * Return: 0
 */

int _command(char *command_array[])
{
	char *str_path;
	char *command;
	pid_t is_child;
	int check;

	str_path = NULL;
	command = NULL;

	command = command_array[0];
	str_path = find(command);
	if (str_path == NULL)
	{
		_cannot_find(command);
		return (3);
	}
	is_child = fork();
	if (is_child < 0)
	{
		perror("Error:");
		return (-1);
	}
	if (is_child > 0)
		wait(&check);
	else if (is_child == 0)
	{
		(execve(str_path, command_array, environ));
		perror("Error:");
		exit(1);
	}
	free(str_path);
	return (0);
}
