#include "shell.h"

/**
 * strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int ia, ja, ka, ma, num = 0;
	char **sa;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (ia = 0; str[ia] != '\0'; ia++)
		if (!is_delim(str[ia], d) && (is_delim(str[ia + 1], d) || !str[ia + 1]))
			num++;

	if (num == 0)
		return (NULL);
	sa = malloc((1 + num) * sizeof(char *));
	if (!sa)
		return (NULL);
	for (ia = 0, ja = 0; ja < num; ja++)
	{
		while (is_delim(str[ia], d))
			ia++;
		ka = 0;
		while (!is_delim(str[ia + ka], d) && str[ia + ka])
			ka++;
		sa[ja] = malloc((ka + 1) * sizeof(char));
		if (!sa[ja])
		{
			for (ka = 0; ka < ja; ka++)
				free(sa[ka]);
			free(sa);
			return (NULL);
		}
		for (ma = 0; ma < ka; ma++)
			sa[ja][ma] = str[ia++];
		sa[ja][ma] = 0;
	}
	sa[ja] = NULL;
	return (sa);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int ie, je, ke, me, num = 0;
	char **se;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (ie = 0; str[ie] != '\0'; ie++)
		if ((str[ie] != d && str[ie + 1] == d) ||
		    (str[ie] != d && !str[ie + 1]) || str[ie + 1] == d)
			num++;
	if (num == 0)
		return (NULL);
	se = malloc((1 + num) * sizeof(char *));
	if (!se)
		return (NULL);
	for (ie = 0, je = 0; je < num; je++)
	{
		while (str[ie] == d && str[ie] != d)
			ie++;
		ke = 0;
		while (str[ie + ke] != d && str[ie + ke] && str[ie + ke] != d)
			ke++;
		se[je] = malloc((ke + 1) * sizeof(char));
		if (!se[je])
		{
			for (ke = 0; ke < je; ke++)
				free(se[ke]);
			free(se);
			return (NULL);
		}
		for (me = 0; me < ke; me++)
			se[je][me] = str[ie++];
		se[je][me] = 0;
	}
	se[je] = NULL;
	return (se);
}
