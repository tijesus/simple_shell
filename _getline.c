#include "shell.h"

/**
 * _getline - function to get input from shell
 * @lnptr: pointer to the lines in the buffer
 * @n: size of the buffer
 * @stream: pointer to the stream to read from
 * Return: character or -1 on failure
*/
ssize_t _getline(char **lnptr, size_t *n, FILE *stream)
{
	static char buf[BUFFSIZE];
	ssize_t char_no;
	static size_t buf_pos;

	if (lnptr == NULL || n == NULL || stream == NULL)
		return (-1);

	if (*lnptr == NULL || *n == 0)
	{
		*lnptr = (char *)malloc(BUFFSIZE * sizeof(char));
		if (*lnptr == NULL)
			return (-1);
		*n = BUFFSIZE;
	}

	char_no = rdline(buf, &buf_pos, lnptr, n, 0);
	return (char_no);
}

/**
 * _memoryAlloc - function to reallocate memory
 * @lnptr: pointer to the buffer containing input
 * @n: size of the buffer
 * @new_size: new size of the buffer to memory  allocation
 * Return: pointer to reallocation or null on failure
*/
char *_memoryAlloc(char **lnptr, size_t *n, size_t new_size)
{
	char *temp;
	*n = new_size;

	temp = (char *)realloc(*lnptr, new_size * sizeof(char));
	if (temp == NULL)
	{
		free(*lnptr);
		*lnptr = NULL;
	}
	return (temp);
}

/**
 * rdline - function to read the line in the stream
 * @buf: pointer to the buffer holding commands
 * @buf_pos: position of the buffer
 * @lnptr: pointer to the buffer containing the commands
 * @n: size of the buffer allocated
 * @cnt: count number of characters to read
 * Return: number of char or -1 on failure
*/
ssize_t rdline(char *buf, size_t *buf_pos, char **lnptr, size_t *n, size_t cnt)
{
	ssize_t chars_read;
	size_t buf_size = *n;
	char *temp;
	char c;

	while ((chars_read = read(STDIN_FILENO, &c, 1)) > 0)
	{
		if (cnt >= buf_size - 1)
		{
			buf_size += BUFFSIZE;
			temp = _memoryAlloc(lnptr, n, buf_size);
			if (temp == NULL)
				return (-1);
			*lnptr = temp;
		}

		if (c == '\n')
		{
			buf[*buf_pos] = '\0';
			*buf_pos = 0;
			(*lnptr)[cnt] = '\0';
			return (cnt);
		}
		(*lnptr)[cnt++] = c;
	}

	if (cnt > 0)
	{
		(*lnptr)[cnt] = '\0';
		return (cnt);
	}
	return (-1);
}
