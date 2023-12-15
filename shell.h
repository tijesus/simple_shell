#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <errno.h>
#define BUFFSIZE 1064

int invalid_absolute_path(char **args);
int _strcmp(const char *str1, const char *str2);
char *_strtok(char *str, char *delim);
char *_removeExtraSpaces(char *input);
int exec_input(char **args, char *envp[], int count, char *argv);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
void _print(char *display);
int check_char(char *input, char *envp[], int count, char *argv);
void _fill_buff_(char *dest, char *source);
char *_strpbrk(const char *str, const char *charset);
int getpath(char **args, int count, char *argv);
char *_getpath(char *str);
void print_environment(char *envp[]);
int _isspace(char ch);
char **tokenizeAndRemoveWhitespace(char *input);
void freeTokens(char **tokens);

#endif
