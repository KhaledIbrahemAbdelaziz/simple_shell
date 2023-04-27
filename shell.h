#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <limits.h>
#include <ctype.h>
#include <errno.h>
#define PROMPT "$ "
#define DELIM " \t\r\n\a"
#define MAX_COMMAND_LENGTH 100
#define MAX_LINE 1024
#define HISTORY_MAXITEMS 100
#define ARG_MAX_COUNT 1024
#define BUFFER_SIZE 1024
/*environ*/
extern char **environ;
void exits(char *argv[], char *buf);
void Env(char *env[]);
void prompt(char *argv[], char *env[]);
int strcompare(char *str1, char *str2);
int strlength(char *str);

#endif /* SHELL_H */
