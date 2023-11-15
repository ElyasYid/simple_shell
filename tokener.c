#include "shell.h"

/**
* split_it - creates tokens from given input
* @buffy: what is split
* Return: array of strings
*/

char **split_it(char *buffy)
{
	char *holder = NULL, *holder_cpy = NULL;
	char *splitted = NULL, *delim = " :\n\t\r";
	char **final = NULL;
	int tokq = 1;
	size_t i = 0, flag = 0;

	holder = _strdup(buffy);
	if (!holder)
		return (NULL);
	holder_cpy = holder;

	while (*holder_cpy)
	{
		if (_strchr(delim, *holder_cpy) != NULL && flag == 0)
		{
			tokq++;
			flag = 1;
		}
		else if (_strchr(delim, *holder_cpy) == NULL && flag == 1)
			flag = 0;
		holder_cpy++;
	}
	final = malloc(sizeof(char *) * (tokq + 1));
	splitted = strtok(holder, delim);
	while (splitted)
	{
		final[i] = _strdup(splitted);
		if (final[i] == NULL)
		{
			free(splitted);
			return (NULL);
		}
		splitted = strtok(NULL, delim);
		i++;
	}
	final[i] = NULL;
	free(holder);
	return (final);
}
