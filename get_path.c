#include "shell.h"
/**
 * _fill_path_buff - fills path buff
 * @path_buff: a buffer to store the path
 * @path_token: a path
 * @cmd: a command
 * Return: 1 (successful) or 0(fail)
 */
void _fill_path_buff(char *path_buff, char *path_token, char *cmd)
{
	char *temp = path_buff;
	/*copy path to path_buff*/
	while (*path_token)
	{
		*temp = *path_token;
		temp++;
		path_token++;
	}
	*temp = '/'; /*add a / to path_buff*/

	temp++;
	/*concatenate cmd to temp*/
	while (*cmd)
	{
		*temp = *cmd;
		cmd++;
		temp++;
	}
	*temp = '\0'; /*null terminate path_buff*/
}

/**
 * __fill_path_buff - fills path buff
 * @_path_buff: a buffer to store the path
 * @path_token: a path
 * @cmd: a command
 * Return: 1 (successful) or 0(fail)
 */
int __fill_path_buff(char *_path_buff, char *path_token, char *cmd)
{
	if (_path_buff != NULL)
		_fill_path_buff(_path_buff, path_token, cmd);
	else
		return (0);
	return (1);
}

/**
 * is_rel_path - check if args[0] is a relative path
 * @args: array of tokens
 * Return: 1 (true) / 0 (false)
*/
int is_rel_path(char **args)
{
	if (args[0][0] == '.' && args[0][1] == '/')
		return (1);
	else if (args[0][0] == '.' && args[0][1] == '.' && args[0][2] == '/')
		return (1);

	return (0);
}

/**
 * _getpath - find the path of a command
 * @str: command
 * Return: the path to the command or NULL if command doesn't exist
 */
char *_getpath(char *str)
{
	char *path, path_cpy[1024], *path_token, *_path_buff, *cmd;
	int found_path = 0;

	cmd = _strtok(str, " ");
	path = getenv("PATH");
	if (path == NULL)
		return (NULL);
	_fill_buff_(path_cpy, path);
	path_token = _strtok(path_cpy, ":");
	if (cmd == NULL)
		return (NULL);
	if (*str != '/')
	{
		while (path_token)
		{
			_path_buff = malloc(BUFFSIZE * sizeof(char));
			if (__fill_path_buff(_path_buff, path_token, cmd) == 0)
				return (NULL);
			if (access(_path_buff, X_OK) == 0)
			{
				found_path = 1;
				break;
			}
			else
			{
				free(_path_buff);
			}
			path_token = _strtok(NULL, ":");
		}
		if (found_path != 1)
		{
			return (NULL);
		}
	}
	else
	{
		_path_buff = malloc(sizeof(char) * (_strlen(str) + 2 + _strlen(path_token)));
		_fill_buff_(_path_buff, cmd);
	}
	return (_path_buff);
}

/**
 * getpath - find the path of a command
 * @args: array of tokens
 * @count: number of times shell has run
 * @argv: name of the shell
 * Return: the path to the command or NULL if command doesn't exist
 */
int getpath(char **args, int count, char *argv)
{
	char *path;
	char temp[BUFFSIZE];

	_fill_buff_(temp, args[0]);
	if (is_rel_path(args))
	{
		path = realpath(args[0], NULL);
		if (path != NULL)
		{
			free(args[0]);
			args[0] = path;
		}
		else
		{
			freeTokens(args);
			fprintf(stderr, "%s: %d: %s: not found\n", argv, count, temp);
			return (127);
		}
	} else if (args[0][0] != '/')
	{
		path = _getpath(args[0]);
		if (path == NULL)
		{
			freeTokens(args);
			fprintf(stderr, "%s: %d: %s: not found\n", argv, count, temp);
			return (127);
		}
		else
		{
			free(args[0]);
			args[0] = path;
		}
	} else
	{
		if (invalid_absolute_path(args) == 127)
			return (127);
	}
	return (0);
}
