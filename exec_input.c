#include "shell.h"

/**
 * exec_input - functions to execute the command
 * @input: command passed
 * @envp: environment variable
 * @count: number of times shell has run
 * @argv: shell name
 * Return: exit status of the executed command
 */
int exec_input(char *input, char *envp[], int count, char *argv)
{
	char *arg[20];
	pid_t child_pid;
	int i, status, exit_status = 0;
	char input_buff[1024];

	_fill_buff_(input_buff, input);
	arg[0] = getpath(input_buff, count, argv);
	if (arg[0] == NULL)
		return (127); /*Return 127 for failure*/

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork error");
		return (1); /*Return 1 for failure*/
	}
	else if (child_pid == 0)
	{
		_strtok(input, " ");
		i = 1;
		while ((arg[i] = _strtok(NULL, " ")) != NULL)
			i++;
		arg[i] = NULL;
		if (execve(arg[0], arg, envp) == -1)
		{
			free(arg[0]);
			perror("./shell");
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
		free(arg[0]);
	}
	return (exit_status);
}
