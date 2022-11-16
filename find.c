#include "shell.h"
/**
 * find - Takes PATH string, tokenizes it, then concats with "/" & cmd
 * @command: command passed from getline in main
 * Return: new_path for use in cmd_read
 */
char *find(char *command)
{
	char *path = _strdup(_get("PATH"));
	int i = 0, j = 0;
	char *path_tokens = strtok(path, ":");
	char *path_array[100];
	char *s2 = command;
	char *new = NULL;
	struct stat buf;

	new = malloc(sizeof(char) * 100);

	if (_get("PATH")[0] == ':')
		if (stat(command, &buf) == 0)
			return (_strdup(command));
	while (path_tokens != NULL)
	{
		path_array[i++] = path_tokens;
		path_tokens = strtok(NULL, ":");
	}
	path_array[i] = NULL;
	for (j = 0; path_array[j]; j++)
	{
		_strcpy(new, path_array[j]);
		_strcat(new, "/");
		_strcat(new, s2);
		_strcat(new, "\0");
		if (stat(new, &buf) == 0)
		{
			free(path);
			return (new);
		}
		else
			new[0] = 0;
	}
	free(path);
	free(new);
	if (stat(command, &buf) == 0)
		return (_strdup(command));
	return (NULL);
}
