#include "shell.h"

/**
* found_de_way - checks whether path is valid
* @de_way: tokenized path
* @mando: user entered command
* Return: path appended with command on success
* NULL on failure
*/

char *found_de_way(char **de_way, char *mando)
{
	int i = 0;
	char *the_way;

	while (de_way[i])
	{
		the_way = extra_way(de_way[i], mando);
		if (access(the_way, F_OK | X_OK) == 0)
			return (the_way);
		free(the_way);
		i++;
	}
	return (NULL);
}
