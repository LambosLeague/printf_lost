#include "holberton.h"
#include <unistd.h>

/**
 * _strlen - counts length of a sting or char pointer
 * @s: accept user input
 * Return: always return legnth counted
 */

int _strlen(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
	count++;
	s++;
	}
	return (count);
}

int _putc(char c)
{
	return (write(1, &c, 1));
}

int _wrt_c(char *ss)
{
	write(1, ss, _strlen(ss));
	return (_strlen(ss));
}

int _putss(char *s)
{
	int i = 0;

	while(*s != '\0')
	{
		_putc(*s);
		i++;
		s++;
	}
	return (i);
}
