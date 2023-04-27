#ifndef SHELL_H
#define SHELL_H
/*All the required libraries*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <errno.h>
#include <sys/wait.h>
/*delimiter def*/
#define TOK_DELIM " \t\r\n\a\""
/*BUFFER_SIZE def*/
#define BUFFER_SIZE 1024
/*environ definition*/
extern char **environ;
/*Task: interactive*/
void user_interactive(void);
/* Input and strings*/
char *read_input(void);
char **lines_sp(char *line);
int run_coms(char **args);
/* Forking and processes  */
int forks(char **args);
/* non - interactive mode fun*/
char *stream(void);
void tok_en(void);
/*The builtin fuctions*/
int cd(char **args);
int my_exit(char **args);
int env(char **args);
int help(char **args);
#endif/*_SHELL_H_*/
