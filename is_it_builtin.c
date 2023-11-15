#include "shell.h"

/**
 * is_it_builtin- checks to see weather its a built in function
 * @comm: parsed user input
 * @buff: user input
 * Return: 1 if command is executed 0 if not
 */

int is_it_builtin(char **comm, char *buff)
{
	if (builtin_executer(comm, buff))
		return (1);
	else if (**comm == '/')
	{
		run_it(comm[0], comm);
		return (1);
	}
	return (0);
}
