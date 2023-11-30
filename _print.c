#include "shell.h"
/**
 * _print - function to print
 * @display: display to terminal
*/
void _print(char *display)
{
	write(1, display, _strlen(display));
}
