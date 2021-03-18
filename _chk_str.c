#include "holberton.h"

int _chk_nw_ln(const char *s)
{
	int cnt = 0, m_cnt = 0;
	char c = 0, cc = 10;

	do
	{	if((*(s + cnt) == c) && (*(s + (cnt - 1)) != cc))
		{
			m_cnt = 0;
			cnt++;
			break;
		}
		if((*(s + cnt) == cc) && (*(s + (cnt + 1)) != c))
		{
			m_cnt += -1;
		}
		if((*(s + cnt) == cc) && (*(s + (cnt + 1)) == c))
		{
			m_cnt += -1;
			break;
		}
	} while(*s++);

	return (m_cnt);
}

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
		cnt = 1;
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
	int x, len = _int_len(i), i_sqrd = _int_sqr(10, len), cnt;
	if((i < 10) && (i >= 0))
	{
		_putc(i + 48);
		cnt = 1;
	}
	else
	{
		if ((i < 0) && (i > -10))
		{
			_putc(45);
			i *= (-1);
			_putc(i + 48);
			cnt = 2;
		}
		else if (i <= -10)
		{
			_putc(45);
			i *= (-1);
			cnt = 1;
			while(len != 0)
			{
				x = (i % i_sqrd) / (i_sqrd / 10);
				_putc(x + 48);
				i_sqrd = i_sqrd / 10;
				len--;
				cnt++;
			}
		}
		else
		{
			cnt = 0;
			while(len != 0)
			{
				x = (i % i_sqrd) / (i_sqrd / 10);
				_putc(x + 48);
				i_sqrd = i_sqrd / 10;
				len--;
				cnt++;
			}
		}
	}
	return (cnt);
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
