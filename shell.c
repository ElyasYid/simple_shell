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
		prompt_user();
		linesize = getline(&line, &bufsize, stdin);
		if (linesize < 0)
			break;
		info.ln_count++;
		if (line[linesize - 1] == '\n')
			line[linesize - 1] = '\0';
		command = tokenizer(line);
		if (command == NULL || *command == NULL || **command == '\0')
			continue;
		if (checker(command, line))
			continue;
		path = find_path();
		paths = tokenizer(path);
		pathcommand = test_path(paths, command[0]);
		if (!pathcommand)
			perror(av[0]);
		else
			execution(pathcommand, command);
	}
	if (linesize < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(line);
	return (0);
}
