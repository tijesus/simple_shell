#include "shell.h"
/**
 * main - entry point
 * @argc: argument count
 * @argv: array of strings
 * @envp: array of environment variables as strings
 * Return: 0 success
 */
int main(int __attribute__((unused)) argc, char *argv[], char *envp[])
{
	char *input = NULL;
	int count = 0;
	int exit_status = 0;
	int _stat;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			count++;
			_print("cisfun$ ");
			_stat = check_char(input, envp, count, argv[0]);
			if (_stat != EOF && _stat != 7)
				exit_status = _stat;
			else if (_stat == 7)
			{
				exit_status = 0;
				continue;
			}
			else if (_stat == EOF)
				exit(0);
		}
	}
	else
	{
		while (1)
		{
			count++;
			_stat = check_char(input, envp, count, argv[0]);
			if (_stat == 7)
				exit_status = 0;
			if (_stat != EOF && _stat != 7)
				exit_status = _stat;
			else
				exit(exit_status);
		}
	}
	return (exit_status);
}
