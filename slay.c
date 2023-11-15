#include "shell.h"

/**
* slay_buffy - frees buffers
* @buffy: buffer to be freed
* Return: no return
*/

void slay_buffy(char **buffy)
{
	int i = 0;

	if (!buffy || buffy == NULL)
		return;
	while (buffy[i])
	{
		free(buffy[i]);
		i++;
	}
	free(buffy);
}
