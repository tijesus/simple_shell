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

void exec_input(char *input);
int _strlen(char *s);
void _print(char *display);
void check_char(char *input, size_t size);


#endif