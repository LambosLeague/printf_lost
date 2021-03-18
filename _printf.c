#include <stdarg.h>
#include "holberton.h"

int _printf(const char *format, ...)
{
	va_list _param;
	va_start(_param, format);
	
	int cnt = 0, _xngd, m_cnt = 0;

	while(*(format + cnt) != '\0')
	{
		_putc(*(format + cnt));

		if (*(format + cnt) == '%')
		{
			_putc(8);
			_xngd += _chk_str(*(format + (cnt + 1)), _param);
			_xngd -= 2;
			cnt += 1;
			_xngd += _chk_nw_ln1(format);
		}
		cnt++;
		m_cnt++;
	}
	m_cnt += _chk_nw_ln(format);
	return (m_cnt + _xngd);
}
