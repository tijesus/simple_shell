#include "shell.h"

/**
 * _free - frees memory
 * @buffer: memory address
 */
void _free(void *buffer)
{
	if (buffer != NULL)
		free(buffer);
}

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
 * getpath - find the path of a command
 * @str: command
 * @count: number of times shell has run
 * @argv: name of the shell
 * Return: the path to the command or NULL if command doesn't exist
 */
char *getpath(char *str, int count, char *argv)
{
	char *path, path_cpy[1024], *path_token, *_path_buff, *cmd;
	int found_path = 0;

	cmd = _strtok(str, " ");
	path = getenv("PATH");
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
			if (access(_path_buff, F_OK) == 0)
			{
				found_path = 1;
				break;
			}
			else
			{
				_free(_path_buff);
			}
			path_token = _strtok(NULL, ":");
		}
		if (found_path != 1)
		{
			fprintf(stderr, "%s: %d: %s: not found\n", argv, count, cmd);
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
