#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

struct builtin
{
	char *env;
	char *exit;
} builtin;

/* environment variables */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/*shell function prototypes*/
int build_builtin(char **argv, char *buffy);
void exit_mando(char **argv, char *buffy);
char *extra_way(char *way, char *mando);
int is_it_builtin(char **comm, char *buff);
void run_it(char *mando, char **argv);
void slay_buffy(char **buffy);
void the_signal(int pop);
char *show_me_de_way(void);
void print_env(void);
char **split_it(char *buffy);
char *found_de_way(char **de_way, char *mando);

/*custom prnt and string prototypes*/
int _putchar(char c);
int print_s(char *s);
char *_strchr(char *s, char c);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);

#endif
