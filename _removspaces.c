#include "shell.h"
/**
 * _isspace - check if a character is a space
 * @ch: a character
 * Return: 1 (true) or 0(false)
 */
int _isspace(char ch)
{
	return (ch == ' ' ||
			ch == '\t' || ch == '\n' || ch == '\r' || ch == '\f' || ch == '\v');
}

/**
 * _removeExtraSpaces - remove extra spaces
 * @input: string
 * Return: pointer to new string
 */
char *_removeExtraSpaces(char *input)
{
	size_t resultIndex = 0, inputLength;
	char *result;
	size_t i;
	int isSpace = 1; /*Set to 1 to remove leading spaces*/
	char buff[1024];

	if (input == NULL)
		return (NULL);
	_fill_buff_(buff, input);
	inputLength = _strlen(buff);
	/*Allocate memory for the modified string*/
	result = (char *)malloc((inputLength + 1) * sizeof(char));
	if (result == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < inputLength; i++)
	{
		if (!_isspace(buff[i]))
		{ /*Copy non-space characters to the result string*/
			result[resultIndex++] = buff[i];
			isSpace = 0;
		}
		else
		{
			if (!isSpace) /*Skip consecutive spaces*/
			{
				result[resultIndex++] = ' ';
				isSpace = 1;
			}
		}
	}
	if (resultIndex > 0 && result[resultIndex - 1] == ' ')
		resultIndex--;
	result[resultIndex] = '\0'; /*Null-terminate the result string*/
	_fill_buff_(input, result);
	free(result);
	return (input);
}
