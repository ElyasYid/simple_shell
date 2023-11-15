#include "shell.h"

/**
 * is_chain - test if current char in buffer is a chain delimeter
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 * Return: 1 if chain delimeter, 0 otherwise
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t jv = *p;

	if (buf[jv] == '|' && buf[jv + 1] == '|')
	{
		buf[jv] = 0;
		jv++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[jv] == '&' && buf[jv + 1] == '&')
	{
		buf[jv] = 0;
		jv++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[jv] == ';')
	{
		buf[jv] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = jv;
	return (1);
}

/**
 * check_chain - checks we should continue chaining based on last status
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 * @i: starting position in buf
 * @len: length of buf
 * Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t jv = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			jv = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			jv = len;
		}
	}

	*p = jv;
}

/**
 * replace_alias - replaces an aliases in the tokenized string
 * @info: the parameter struct
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(info_t *info)
{
	int ih;
	list_t *node;
	char *ph;

	for (ih = 0; ih < 10; ih++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		ph = _strchr(node->str, '=');
		if (!ph)
			return (0);
		ph = _strdup(ph + 1);
		if (!ph)
			return (0);
		info->argv[0] = ph;
	}
	return (1);
}

/**
 * replace_vars - replaces vars in the tokenized string
 * @info: the parameter struct
 * Return: 1 if replaced, 0 otherwise
 */
int replace_vars(info_t *info)
{
	int ig = 0;
	list_t *node;

	for (ig = 0; info->argv[ig]; ig++)
	{
		if (info->argv[ig][0] != '$' || !info->argv[ig][1])
			continue;

		if (!_strcmp(info->argv[ig], "$?"))
		{
			replace_string(&(info->argv[ig]),
				_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[ig], "$$"))
		{
			replace_string(&(info->argv[ig]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[ig][1], '=');
		if (node)
		{
			replace_string(&(info->argv[ig]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[ig], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - replaces string
 * @old: address of old string
 * @new: new string
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
