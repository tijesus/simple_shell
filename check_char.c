#include "shell.h"
#include <signal.h>

/**
 * all_space - checks if a string is all space
 * @input: string
 * Return: 1 for true and 0 for false
*/
int all_space(char *input)
{
	int __attribute((unused)) is_all_whitespace = 1;
	int i;

	for (i = 0; input[i] != '\0'; i++)
	{
		if (!_isspace(input[i]))
		{
			is_all_whitespace = 0;
			return (0);
		}
	}
	return (1);
}

/**
 * null_term - null terminate a string
 * @input: the string from getline function
 * Return: null terminated string
*/
char *null_term(char *input)
{
	int i;

	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == '\n')
			input[i] = '\0';
	}
	return (input);
}

/**
 * check_char - check through the characters in the commamnd
 * @input: the character to check
 * @envp: environment variables
 * @argv: shell name
 * @count: number of times the shell has run
 * Return: exit status of the executed command
 */
int check_char(char *input, char *envp[], int count, char *argv)
{
	ssize_t count_chars;
	int exit_status = 0;
	size_t size = 0;

	count_chars = _getline(&input, &size, stdin);
	if (count_chars == -1)
	{
		free(input);
		if (isatty(STDIN_FILENO))
			write(1, "\n", 1);
		return (-1);
	}
	if (input[0] == '\n')
	{
		free(input);
		return (7);
	}
	null_term(input);
	if (all_space(input))
		return (7);
	_removeExtraSpaces(input);
	if (*input == ' ' && input[1] == '\0')
		return (7);
	if (_strcmp(input, "exit") == 0)
	{
		free(input);
		exit(EXIT_SUCCESS);
	}
	else if (_strcmp(input, "env") == 0)
	{
		free(input);
		print_environment(envp);
	}
	else
	{
		exit_status = exec_input(input, envp, count, argv);
		free(input);
	}
	return (exit_status);
}
