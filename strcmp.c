/**
 * _strcmp - compare two strings
 * @str1: string
 * @str2: string
 * Return: 0 if both are same and 1 if they're not
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 == *str2)
		return (0);
	return (1);
}
