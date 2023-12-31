#include "shell.h"

/**
 * builtin - print the current environment
 *
 * Return: none
 */
void builtin(void)
{
	char **ev;

	for (ev = environ; *ev != NULL; ev++)
	{
		write(STDOUT_FILENO, *ev, _strlen(*ev));
		write(STDOUT_FILENO, "\n", 1);
	}
}
