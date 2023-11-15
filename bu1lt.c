#include "shell.h"

/**
 * _myhistory - displays the history list
 * @info: Structure containing potential arguments
 * Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *x, y;
	int doty;

	x = _strchr(str, '=');
	if (!x)
		return (1);
	y = *x;
	*x = 0;
	doty = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*x = y;
	return (doty);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *x;

	x = _strchr(str, '=');
	if (!x)
		return (1);
	if (!*++x)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *x = NULL, *z = NULL;

	if (node)
	{
		x = _strchr(node->str, '=');
		for (z = node->str; z <= x; z++)
			_putchar(*z);
		_putchar('\'');
		_puts(x + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments
 * Return: Always 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *x = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		x = _strchr(info->argv[i], '=');
		if (x)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
