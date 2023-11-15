#include "shell.h"

/**
* main - entry point
* @argc: argument count
* @argv: argument array
* @envp: environment array
* Return: 0
*/

int main(int argc, char *argv[], char *envp[])
{
	char *buffy = NULL, *way_mando = NULL, *de_way = NULL;
	size_t buffq = 0;
	ssize_t lineq = 0;
	char **mando = NULL, **ways = NULL;

	(void)envp, (void)argv;

	if (argc < 1)
		return (-1);

	signal(SIGINT, the_signal);

	while (1)
	{
		slay_buffy(mando);
		slay_buffy(ways);
		free(way_mando);
		write(STDOUT_FILENO, "SHello> ", 8);
		lineq = getline(&buffy, &buffq, stdin);
		if (linq < 0)
			break;
		info.ln_count++;
		if (buffy[lineq - 1] == '\n')
			buffy[lineq - 1] = '\0';
		mando = split_it(buffy);
		if (mando == NULL || *mando == NULL || **mando == '\0')
			continue;
		if (is_it_builtin(mando, buffy))
			continue;
		de_way = show_me_de_way();
		ways = split_it(de_way);
		way_mando = found_de_way(ways, mando[0]);
		if (!way_mando)
			perror(argv[0]);
		else
			run_it(way_mando, mando);
	}
	if (linesize < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(line);
	return (0);
}
