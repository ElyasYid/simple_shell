#include "shell.h"

/**
* extra_way - includes path to command if provided
* @way: path of command
* @mando: user entered command
* Return: buffer containing command success
* NULL on failure
*/

char *extra_way(char *way, char *mando)
{
	char *buffy;
	size_t i = 0;
	size_t j = 0;

	if (mando == 0)
		mando = "";

	if (way == 0)
		way = "";

	buffy = malloc(sizeof(char) * (_strlen(way) + _strlen(mando) + 2));
	if (!buffy)
		return (NULL);

	while (way[i])
	{
		buffy[i] = way[i];
		i++;
	}

	if (way[i - 1] != '/')
	{
		buffy[i] = '/';
		i++;
	}
	while (mando[j])
	{
		buffy[i + j] = mando[j];
		j++;
	}
	buffy[i + j] = '\0';
	return (buffy);
}
