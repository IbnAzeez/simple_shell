#include "shell.h"

/**
 * main - print prompt, handle EOF, read file_stream
 * @argc: arg count
 * @argv: argv for command
 * Return: Always 0.
 */

int main(int argc __attribute__((unused)), char **argv)
{
	char *s;
	size_t buf_size;
	ssize_t file_stream;
	char *name;

	s = NULL;
	buf_size = 0;
	file_stream = 0;

	/* Surpress warning of unused function argument*/
	(void) argc;

	name = argv[0];

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(1, "$ ", 2);
		file_stream = getline(&s, &buf_size, stdin);
		if (file_stream == -1)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(1, "\n", 1);
			break;
		}
		if (s[file_stream - 1]  == '\n')
			s[file_stream - 1]  = '\0';
		if (*s == '\0')
			continue;
		if (command_line(s, file_stream) == 2)
			break;
	}
	free(s);
	s = NULL;
	return (0);
}
