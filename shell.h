#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define BUFFER 1024
#define SEPARATORS " \n"
#define ENV_SEPARATOR "="
#define ESCAPE_SEPARATOR "#"
#define PATH_SEPARATOR ":"
#define PROMPT "$ "
#define ERR_FORK "Unable to fork and create child process\n"
#define ERR_MALLOC "Unable to malloc space\n"
#define ERR_PATH "No such file or directory\n"

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


/**
 * struct list_s - linked list of variables
 * @value: value
 * @next: pointer to next node
 * Description: generic linked list struct for variables.
 */
typedef struct list_s
{
	char *value;
	struct list_s *next;
} list_s;

/**
 * struct built_s - linked list of builtins
 * @name: name of builtin
 * @p: pointer to function
 * Description: struct for builtin functions.
 */
typedef struct built_s
{
	char *name;
	int (*p)(void);
} built_s;

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
int main(void);
char **_strtow(char *str, char *separators, char *escape_separators);
void _freeCharDoublePointer(char **ptr);
void prompt(int fd, struct stat buf);
void _puts(char *str);
char *_getline(FILE *fp);
int _strncmp(char *name, char *variable, unsigned int length);
char **tokenizer(char *str);
void errors(int error);
int builtins(char **tokens);
int shell_num_builtins(built_s builtin[]);
int shell_exit(void);
int shell_env(void);
char *_search(char *command, char *fullpath, char *path);
int child(char *fullpath, char **tokens);
void free_all(char **tokens, char *path, char *line, char *fullpath, int flag);
void free_dp(char **array, unsigned int length);

#endif
