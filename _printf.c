#include <stdarg.h>
#include "holberton.h"

int _printf(const char *format, ...)
{
	va_list _param;
	va_start(_param, format);
	
	int cnt = 0, _xngd;

	while(*(format + cnt) != '\0')
	{
		_putc(*(format + cnt));

		if (*(format + cnt) == '%')
		{
			_putc(8);
			_xngd += _chk_str(*(format + (cnt + 1)), _param);
			_xngd -= 2;
			cnt += 1;
		}
		cnt++;
	}
	return ((cnt + _xngd) - 1);
}
