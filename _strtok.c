#include "shell.h"

/**
 * _strtok - tokenize strings
 * @str: the string to be tokenized
 * @delim: the string to be used as a delimeter
 * Return: pointer to the tokens
 */
char *_strtok(char *str, char *delim)
{
	static char *_str;
	char *token = NULL;
	char *_delim = NULL;

	if (str != NULL)
		_str = str;

	/*If _str is NULL, there are no more tokens*/
	if (_str == NULL)
		return (NULL);

	token = _str;
	_delim = _strpbrk(_str, delim);

	if (_delim != NULL)
	{
		*_delim = '\0';
		_str = _delim + 1;
	}
	else
	{
		/*If delimiter not found, set _str to NULL for next call*/
		_str = NULL;
	}

	return (token);
}
