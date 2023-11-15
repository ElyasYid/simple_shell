#include "shell.h"

/**
* _strncmp - compares two strings up to n bytes
* @s1: compared to s2
* @s2: compared to s1
* @n: number of bytes
* Return: difference between s1 and s2
*/
int _strncmp(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
