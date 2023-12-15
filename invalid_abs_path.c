#include "shell.h"
/**
 * invalid_absolute_path - check if path is valid
 * @args: array of tokens
 * Return: 127 (invalid) / 0 (valid)
*/
int invalid_absolute_path(char **args)
{
	if (access(args[0], X_OK) != 0)
		return (127);
	return (0);
}
