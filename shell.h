#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>


extern char **environ;
char *_getline();
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
void prompt(int);
void tokenizer(char *buffer, int);
void exec(char **, char *, int);
void find(char **, char *, int);
int _atoi(char *s);
char *_strcat(char *dest, char *src);

#endif
