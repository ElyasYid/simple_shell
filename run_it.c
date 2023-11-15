#include "shell.h"

/**
 * run_it - runs user commands
 * @mando: command
 * @argv: array of pointers to commands
 * Return: 0
 */

void run_it(char *mando, char **argv)
{
	pid_t pid;
	int st;
	char **ev = environ;

	pid = fork();
	if (pid < 0)
		perror(mando);
	if (pid == 0)
	{
		execve(mando, argv, ev);
		perror(mando);
		free(mando);
		slay_buffy(argv);
		exit(98);
	}
	else
		wait(&st);
}
