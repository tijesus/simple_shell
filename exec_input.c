#include "shell.h"
/**
 * exec_input - functions to execute the command
 * @input: command passed
*/
void exec_input(char *input)
{
	char *arg[] = {NULL, NULL};
	pid_t child_pid;
	int status;

	arg[0] = input;
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		free(input);
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(arg[0], arg, NULL) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
}
