#include "shell.h"
/**
 * main - entry point
 * Return: 0 success
*/
int main(void)
{
	char input[200];

	while (true)
	{
		my_print("Tijesus$ ");
		check_char(input, sizeof(input));

	}
}
