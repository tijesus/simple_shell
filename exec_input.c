#include "shell.h"
/**
 * exec_input - functions to execute the command
 * @input: command passed
*/
void exec_input(char *input)
{
	char *arg[20];
	pid_t child_pid;
	int i, status;

	arg[0] = input;
	child_pid = fork();
	if (child_pid == -1)
		perror("fork error");
	else if (child_pid == 0)
	{
		/*seperate strings passed into the terminal*/
		arg[0] = strtok(input, " ");
		i = 1;
		while ((arg[i] = strtok(NULL, " ")) != NULL)
			i++;
		arg[i] = NULL;
		if (execve(arg[0], arg, NULL) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
		waitpid(child_pid, &status, 0);
}
