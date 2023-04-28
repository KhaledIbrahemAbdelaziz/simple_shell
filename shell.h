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
/*MAX_LINE def*/
#define MAX_LINE 1024
/*environ definition*/
extern char **environ;
/*Task: interactive*/
void user_interactive(void);
/* Input and strings*/
char *read_input(void);
char **lines_sp(char *line);
int run_coms(char **args);
/*parser*/
int new_proc(char **args);
char **parse_command(char *line);
int command_sep(char **args);
int new_proc(char **args);
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
int set_env(char **args);
int unset_env(char **args);
#endif/*_SHELL_H_*/
