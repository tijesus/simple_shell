#include "shell.h"
/**
 * _strlen - function to output string length
 * @s: pointer to s
 * Return: 0 success
 */
int _strlen(char *s)
{
	int i;
	int count = 0;

	for (i = 0; s[i] != '\0'; i++)
		count++;
	return (count);
}
