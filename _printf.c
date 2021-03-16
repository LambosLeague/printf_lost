#include <stdarg.h>
#include <stdio.h>
#include "holberton.h"

int _printf(const char *format, ...)
{
	va_list _param;
	va_start(_param, format);
	
	int cnt = 0, cnts = 0, cntd = 0;
	
	while(*(format + cnt) != '\0')
	{
		putc(*(format + cnt), stdout);

		if (*(format + cnt) == '%' && *(format + (cnt + 1)) == 's')
		{
			_chk_str(format);
			putc(8, stdout);
			char *ss = va_arg(_param, char *);
			fputs(ss, stdout);
			cnts += _strlen(ss);
			cnt += 1;
		}
		else if (*(format + cnt) == '%' && *(format + (cnt + 1)) == 'c')
		{
			char c = va_arg(_param, char);
			putc(c, stdout);
		}
		cnt++;
		cntd++;
	}
	return 0;
}
