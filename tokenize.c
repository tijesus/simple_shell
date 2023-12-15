#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "shell.h"

/**
 * countTokens - Helper function to count the number of tokens in a string
 * @input: string
 * Return: number of tokens
 */
static int countTokens(const char *input)
{
	int tokenCount = 0;
	const char *ptr = input;

	while (*ptr)
	{
		while (isspace(*ptr))
			ptr++;
		if (*ptr)
		{
			tokenCount++;
			while (*ptr && !isspace(*ptr))
				ptr++;
		}
	}

	return (tokenCount);
}

/**
 * tokenize - Helper function to tokenize a string
 * @input: string
 * @tokenCount: number of tokens
 * Return: array of tokenized strings
 */
static char **tokenize(const char *input, int tokenCount)
{
	const char *ptr = input;
	char **tokens;
	size_t tokenLength;
	const char *start;
	int index = 0;

	tokens = (char **)malloc((tokenCount + 1) * sizeof(char *));
	if (!tokens)
	{
		return (NULL);
	}

	ptr = input;
	while (*ptr)
	{
		while (isspace(*ptr))
			ptr++;
		if (*ptr)
		{
			start = ptr;
			while (*ptr && !isspace(*ptr))
				ptr++;
			tokenLength = ptr - start;

			tokens[index] = (char *)malloc((tokenLength + 1) * sizeof(char));
			if (!tokens[index])
			{
				freeTokens(tokens);
				return (NULL);
			}

			strncpy(tokens[index], start, tokenLength);
			tokens[index++][tokenLength] = '\0';
		}
	}

	tokens[index] = NULL;
	return (tokens);
}

/**
 * tokenizeAndRemoveWhitespace - Function to tokenize a string and
 * remove spaces, tabs, and newlines
 * @input: string
 * Return: array of tokenized strings
 */
char **tokenizeAndRemoveWhitespace(char *input)
{
	int tokenCount = countTokens(input);

	if (tokenCount == 0)
	{
		free(input);
		return (NULL);
	}

	char **tokens = tokenize(input, tokenCount);

	free(input);
	return (tokens);
}

/**
 * freeTokens - Function to free the memory allocated for tokens
 * @tokens: array of string tokens
 */
void freeTokens(char **tokens)
{
	for (int i = 0; tokens[i]; i++)
		free(tokens[i]);
	free(tokens);
}
