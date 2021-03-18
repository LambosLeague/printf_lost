#include "holberton.h"
#include <unistd.h>

/**
 * _strlen - counts length of a sting or char pointer
 * @s: accept user input
 * Return: always return legnth counted
 */
int _chk_nw_ln1(const char *s)
{
	int cnt = 0, m_cnt = 0;
	char c = 0, cc = 10;

	while (*s++)
	{	if((*(s + cnt) == c) && (*(s + (cnt - 1)) != cc))
		{
			m_cnt++;
			cnt++;
			break;
		}
		if((*(s + cnt) == cc) && (*(s + (cnt + 1)) != c))
		{
			m_cnt = 0;
			cnt++;
		}
		if((*(s + cnt) == cc) && (*(s + (cnt + 1)) == c))
		{
			m_cnt += 1;
			break;
		}
	}
	return (m_cnt);
}

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
