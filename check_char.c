#include "shell.h"

/**
 * check_char - check through the characters in the commamnd
 * @input: the character to check
 * @size: the size of the input
*/
void check_char(char *input, size_t size)
{
	ssize_t count_chars;
	int i;

	size = 0;
	input = NULL;
	count_chars = getline(&input, &size, stdin);
	if (count_chars == -1)
	{
		exit(EXIT_FAILURE);
	}

	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == '\n')
		input[i] = '\0';
	}
	exec_input(input);
}

