#include "shell.h"

/**
 * _cannot_find - prints when command is not found in path
 *
 * @command: a string provided by the stdin
 */

void _cannot_find(char *command)
{
	write(2, name, _strlen(name));
	write(2, ": 1: ", 5);
	write(2, command, _strlen(command));
	write(2, ": not found\n", 12);
}
