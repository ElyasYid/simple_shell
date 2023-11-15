#include "shell.h"

/**
* exit_mando - handles the exit command
* @argv: tokenized command
* @buffy: input read from stdin
* Return: no return
*/

void exit_mando(char **argv, char *buffy)
{
	free(buffy);
	slay_buffy(argv);
	exit(0);
}
