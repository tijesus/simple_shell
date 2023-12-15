#include "shell.h"

/**
 * exec_input - functions to execute the command
 * @args: array of tokens passed
 * @envp: environment variable
 * @count: number of times shell has run
 * @argv: shell name
 * Return: exit status of the executed command
 */
int exec_input(char **args, char *envp[], int count, char *argv)
{
	pid_t child_pid;
	int i, status, exit_status = 0;

	if (getpath(args, count, argv) == 127)
		return (127); /*Return 127 for failure*/

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork error");
		return (1); /*Return 1 for failure*/
	}
	else if (child_pid == 0)
	{
		if (execve(args[0], args, envp) == -1)
		{
			freeTokens(args);
			perror(".execve");
			exit((errno == 2 ? 127 : errno));
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		if (WIFEXITED(status))
			exit_status = WEXITSTATUS(status);
		else
			exit_status = 1; /*Child process did not exit normally*/
		freeTokens(args);
	}
	return (exit_status);
}
