#include "shell.h"

/**
* show_me_de_way - finds path from the global env
* Return: NULL if path is not found or 'path' if found.
*/

char *show_me_de_way(void)
{
	int i;
	char **ev = habitat;
	char *de_way = NULL;

	while (*ev)
	{
		if (_strncmp(*ev, "PATH=", 5) == 0)
		{
			de_way = *ev;
			while (*de_way && i < 5)
			{
				de_way++;
				i++;
			}
			return (de_way);
		}
		ev++;
	}
	return (NULL);
}
