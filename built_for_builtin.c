#include "shell.h"

/**
* build_builtin - handles execution of some builtin func
* @argv: tokenized commands
* @buffy: input read from stdin
* Return: 1 if executed, 0 if not
*/

int build_builtin(char **argv, char *buffy)
{
	struct builtin builtin = {"env", "exit"};

	if (_strcmp(*argv, builtin.env) == 0)
	{
		print_env();
		return (1);
	}
	else if (_strcmp(*argv, builtin.exit) == 0)
	{
		exit_mando(argv, buffy);
		return (1);
	}
	return (0);
}
