#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <errno.h>
#define BUFFSIZE 1064

int _strcmp(const char *str1, const char *str2);
char *_strtok(char *str, char *delim);
char *_removeExtraSpaces(char *input);
int exec_input(char *input, char *envp[], int count, char *argv);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
void _print(char *display);
int check_char(char *input, char *envp[], int count, char *argv);
void _fill_buff_(char *dest, char *source);
char *_strpbrk(const char *str, const char *charset);
char *getpath(char *str, int count, char *argv);
void print_environment(char *envp[]);
int _isspace(char ch);
ssize_t _getline(char **lnptr, size_t *n, FILE *stream);
char *_memoryAlloc(char **lnptr, size_t *n, size_t new_size);
ssize_t rdline(char *buf, size_t *buf_pos, char **lnptr, size_t *n, size_t cnt);

#endif
