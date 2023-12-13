#include "shell.h"

/**
 * print_environment - print environment variable
 * @envp: environment variables
 */
void print_environment(char *envp[])
{
	char *array[] = {"/bin/sh", "-c", "env", NULL};

	if (fork() == 0)
	{
		execve(array[0], array, envp);
	}
	else
	{
		wait(NULL);
	}

}
