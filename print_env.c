#include "shell.h"

/**
* print_env - prints the environment string to stdout
* Return: 0
*/

void print_env(void)
{
	int i = 0;
	char **ev = habitat;

	while (ev[i])
	{
		write(STDOUT_FILENO, (const void *)ev[i], _strlen(ev[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
