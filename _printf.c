#include <stdarg.h>
#include "holberton.h"

int _printf(const char *format, ...)
{
	va_list _param;
	va_start(_param, format);
	
	int cnt = 0;

	while(*(format + cnt) != '\0')
	{
		_putc(*(format + cnt));

		if (*(format + cnt) == '%')
		{
			_putc(8);
			_chk_str(*(format + (cnt + 1)), _param);
			cnt += 1;
		}
		_chk_nw_ln(format);
		cnt++;
	}
	return 0;
}
