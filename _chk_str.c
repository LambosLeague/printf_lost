#include "holberton.h"

int _chk_str(char s, va_list _param)
{
	char *ss, sc;
	int i, x, y, cnt = 0;

	switch (s)
	{
		case 's':
		ss = va_arg(_param, char *);
		cnt = cnt + _putss(ss);
		break;
		case 'c':
		sc = va_arg(_param, int);
		_putc(sc);
		cnt++;
		break;
		case 'd':
		i = va_arg(_param, int);
		cnt = cnt + _chk_int(i);;
		break;
		case 'i':
		x = va_arg(_param, int);
		cnt = cnt + _chk_int(x);
		break;
		case '%':
		y = va_arg(_param, int);
		cnt = cnt + _chk_int(y) + 1;
		_putc('%');
		break;
	}
	return cnt;
}

int _chk_int(int i)
{
	int x, len = _int_len(i), i_sqrd = _int_sqr(10, len);
	if((i < 10) && (i >= 0))
		_putc(i + 48);
	else
	{
		if ((i < 0) && (i > -10))
		{
			_putc(45);
			i *= (-1);
			_putc(i + 48);
		}
		else if (i <= -10)
		{
			_putc(45);
			i *= (-1);
			while(len != 0)
			{
				x = (i % i_sqrd) / (i_sqrd / 10);
				_putc(x + 48);
				i_sqrd = i_sqrd / 10;
				len--;
			}
		}
		else
		{
			while(len != 0)
			{
				x = (i % i_sqrd) / (i_sqrd / 10);
				_putc(x + 48);
				i_sqrd = i_sqrd / 10;
				len--;
			}
		}
	}
	return (_int_len(i));
}

int _int_len(int i)
{
	int cnt = 0;
	
	if (i < 0)
		i *= (-1);

	while(i != 0)
	{
		i /= 10;
		cnt++;
	}
	return (cnt);
}

int _int_sqr(int x, int y)
{
	if(x == 0)
		return (0);
	if(y < 0)
		return (-1);
	if(y == 0 || x == 1)
		return (1);
	if(y == 1)
		return (x);

	return (x * _int_sqr(x, ( y = y - 1)));
}
