#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include "shell.h"
/**
 * _exit - exits the shell
 * @commandName: command name
 */
int _exitCommand(char *commandName)
{
	if (_strcmp(commandName, "exit") == 0)
		exit(EXIT_SUCCESS);
	return (0);
}
