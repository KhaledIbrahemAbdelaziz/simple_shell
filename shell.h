#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
extern char **environ;

void prompt(char *argv[], char *env[]);
void exits(char *argv[], char *buf);
void Env(char *env[]);
int strcompare(char *str1, char *str2);
int strlength(char *str);

#endif /* SHELL_H */
