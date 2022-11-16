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
#define PROMPT "$ "
#define ERR_FORK "Unable to fork and create child process\n"
#define ERR_MALLOC "Unable to malloc space\n"
#define ERR_PATH "No such file or directory\n"

extern char **environ;
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

int _strlen(char *str);
int _strcmp(char *s1, char *s2);
/*int exit_command(char *commandName);*/
char *_strcpy(char *dest, char *src);
int _strn_cmp(char *name, char *variable, unsigned int length);
list_s *pathlist(char *variable, list_s *head);
int main(void);
void prompt(int fd, struct stat buf);
void _puts(char *str);
char *_getline(FILE *fp);
int _strncmp(char *name, char *variable, unsigned int length);
char **tokenizer(char *str);
void errors(int error);
int builtin_exec(char **tokens);
int shell_num_builtins(built_s builtin[]);
int shell_exit(void);
int shell_env(void);
char *_search(char *command, char *fullpath, char *path);
int child(char *fullpath, char **tokens);
void free_all(char **tokens, char *path, char *line, char *fullpath, int flag);
void free_dp(char **array, unsigned int length);
char **copy_env(char **environ_copy, unsigned int environ_length);
char *_getenv(const char *name);

#endif
