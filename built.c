#include "shell.h"

/**
 * _myexit - exits the shell
 * @info: Structure containing potential arguments
 *  Return: exits with a given exit status
 */
int _myexit(info_t *info)
{
	int chexit;

	if (info->argv[1])
	{
		chexit = _erratoi(info->argv[1]);
		if (chexit == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
/**
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments
 * Return: Always 0
 */
int _mycd(info_t *info)
{
	char *bobo, *coco, buffer[1024];
	int roro;

	bobo = getcwd(buffer, 1024);
	if (!bobo)
		_puts("getcwdfail\n");
	if (!info->argv[1])
	{
		coco = _getenv(info, "HOME=");
		if (!coco)
			chdir((coco = _getenv(info, "PWD=")) ? coco : "/");
		else
			roro = chdir(coco);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(bobo);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir((coco = _getenv(info, "OLDPWD=")) ? coco : "/");
	}
	else
		roro = chdir(info->argv[1]);
	if (roro == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
