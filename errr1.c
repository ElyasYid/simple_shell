#include "shell.h"

/**
 * _erratoi - converts a string to an integer
 * @sali: the string to be converted
 * Return: 0 if no numbers in string or conv num
 */
int _erratoi(char *sali)
{
	int d;
	unsigned long int result = 0;

	if (*sali == '+')
		sali++;
	for (d = 0; sali[d] != '\0'; d++)
	{
		if (sali[d] >= '0' && sali[d] <= '9')
		{
			result *= 10;
			result += (sali[d] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers, result success, -1 error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - function prints a integer
 * @input: the input
 * @fd: the filedescriptor to write
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int k, cnt = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		cnt++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (k = 1000000000; k > 1; k /= 10)
	{
		if (_abs_ / k)
		{
			__putchar('0' + current / k);
			cnt++;
		}
		current %= k;
	}
	__putchar('0' + current);
	cnt++;

	return (cnt);
}

/**
 * convert_number - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int ll;

	for (ll = 0; buf[ll] != '\0'; ll++)
		if (buf[ll] == '#' && (!ll || buf[ll - 1] == ' '))
		{
			buf[ll] = '\0';
			break;
		}
}
