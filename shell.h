#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

int _env(void);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
int _exit(char *commandName);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void cannot_find(char *commandd);
int portable_command(char *command_array[]);
char *_getenv(char *variable);
int _strn_cmp(char *s1, char *s2, int n);
int command_line(char *s, size_t __attribute__((unused))file_stream);
char *find(char *command);
int _command(char *command_array[]);

#endif
