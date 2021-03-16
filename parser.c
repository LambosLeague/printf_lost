#include "holberton.h"

/**
 * parser - receives a string and other necessary parameters
 * to print a formatted sting.
 * @format: string coprising of all the desired chars
 * @f_list: list of all possible functions.
 * @arg_list: list of all args passed to the program
 * Return: total count of chars printed.
 */

int parser(const char *format, convert_t f_list[], va_list arg_list)
{
  int i, j, r_val, printed_chars;

  printed_chars = 0;
  /*iterate through the main str*/
  for (i = 0; format[i] != '\0'; i++)
    {
      /*check for format specifiers*/
      if (format[i] == '%')
	{
	  /*iterate through struct to get the right func*/
	  for (j = 0; f_list[j].sym != NULL; j++)
	    {
	      if (format[i + 1] == f_list[j].sym[0])
		{
		  r_val = f_list[j].f(arg_list);
		  if (r_val == -1)
		    return (-1);
		  printed_chars += r_val;
		  break;
}
}
	  if (f_list[j].sym == NULL && format[i + 1] != ' ')
	    {
	      if (format[i + 1] != '\0')
		{
		  _write_char(format[i]);
		  _write_char(format[i + j]);
		  printed_chars = printed_chars + 2;
		}
	      else
		return (-1);
	    }
	  /*update i to skip format symbols*/
	  i = i + 1;
}
      else
	{
	  /*call the write func*/
	  _write_char(format[i]);
	  printed_chars++;
	}
}
  return (printed_chars);
}
