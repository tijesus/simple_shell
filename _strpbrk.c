
/**
 * _strpbrk - find the first occurence of a character in a string
 * @str: the string to search
 * @charset: a string of characters to check for
 * Return: pointer to first occurence
 */
#include <stdio.h>

char *_strpbrk(const char *str, const char *charset)
{
	if (str == NULL || charset == NULL)
		return (NULL);

	while (*str != '\0')
	{
		const char *current_char = charset;

		while (*current_char != '\0')
		{
			if (*str == *current_char)
				return ((char *)str);
			current_char++;
		}
		str++;
	}
	return (NULL);
}
