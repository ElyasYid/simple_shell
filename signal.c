#include "shell.h"

/**
 * the_signal- checks if interactive mode
 * @pop: the signal number
 * Return: nothing
 */

void the_signal(int pop)
{
	(void)pop;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}
