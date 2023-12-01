#include "shell.h"
#include <string.h>
/**
 * _strcpy - copy from one place to another
 * @dest: pointer
 * @src: pointer
 * Return: the copied string
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
		dest[i] = '\0';
	return (dest);
}
