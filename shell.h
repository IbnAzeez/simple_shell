#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define BUFFER_SIZE 256
#define SEPARATORS " \n"
#define ENV_SEPARATOR "="
#define ESCAPE_SEPARATOR "#"
#define PATH_SEPARATOR ":"

extern char **environ;
char *name;

/**
 * struct environment_s - environment variable
 * @name: environment name
 * @value: environment value
 * @next: points to the next node
 */
typedef struct environment_s
{
	char *name;   /* ex: PATH */
	char *value;  /* ex: /bin:/usr/bin */
	char *global; /* PATH=/bin:/usr/bin */
	struct environment_s *next;
} environment_t;

/**
 * struct appData_s - data variable
 * @arg: argument's array
 * @buffer: buffer
 * @cmd: command name
 */
typedef struct appData_s
{
	char **arg;
	char *buffer;
	char *cmd;
	char **cmdList;
	char **hist;
	char *prog;
	environment_t *env;
} appData_t;

environment_t *_addenv(
		environment_t **HdNode,
		char *global_env
		);

int _env(void);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
/*int exit_command(char *commandName);*/
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void _cannot_find(char *command);
int portable_command(char *command_array[]);
char *_get(char *variable);
int _strn_cmp(char *s1, char *s2, int n);
int command_line(char *s, size_t __attribute__((unused))file_stream);
char *find(char *command);
int _command(char *command_array[]);
char *_str_concat(char *S1, char *S2);
void _setenv(environment_t *EnvList, char *env_name, char *env_value, int replace);
environment_t *_getLast(environment_t *HdNode);
environment_t *_getenv(environment_t *node, char *env_name);
environment_t *_createenv(char *global_env);
void _changeDir(appData_t *data);
void _anyDir(appData_t *data, char *CurrentDir);
void _homeDir(appData_t *data, char *CurrentDir);
void _prevDir(appData_t *data, char *CurrentDir);
char *_create(char *env_name, char *env_value);
char *_getenvname(char *variable);
char *_getenvvalue(char *variable);
int main(int argc __attribute__((unused)), char **argv);
char **_strtow(char *str, char *separators, char *escape_separators);
void _freeCharDoublePointer(char **ptr);

#endif
