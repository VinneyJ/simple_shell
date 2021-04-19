#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

extern char **environ;

char *_readline(void);
char **split_line(char *line);
int execute(char **argv, char **comm, int count);

void error_mess(char **argv, char **comm, int count);
int _puterror(char c);

void Sigint_handler(int sign);

char *_getenv(const char *name, char **environ);
char *appcmd(char *envcmd, char *envdir, char *command);
char **store_path_command(char *fir_com);

void shell_exit(char **args);
void _env(char **environ);

int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strdup(char *s);
int _strlen(const char *s);
int _strncmp(const char *s1, const char *s2, size_t n);

char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_dbl_ptr(char **dbl_ptr);

#endif
