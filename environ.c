#include "shell.h"

/**
 * _myenv - prints the current environment
 * @info: Structure containing potential arguments
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}
/**
 * _getenv - gets the value of an environ variable
 * @info: structure with potential arguments
 * @name: env var name
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *x;

	while (node)
	{
		x = starts_with(node->str, name);
		if (x && *x)
			return (x);
		node = node->next;
	}
	return (NULL);
}
/**
 * _mysetenv - Initialize or mod a new environment variable
 * @info: Structure containing potential argument
 * Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("unallowed number of arguments\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}
/**
 * _myunsetenv - Remove an environment variable
 * @info: Structure containing potential argument
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int l;

	if (info->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}
	for (l = 1; l <= info->argc; l++)
		_unsetenv(info, info->argv[l]);

	return (0);
}
/**
 * populate_env_list - populates env linked list
 * @info: structure containing potential argument
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t k;

	for (k = 0; environ[k]; k++)
		add_node_end(&node, environ[k], 0);
	info->env = node;
	return (0);
}
