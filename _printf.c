#include "holberton.h"

/**
 * _printf - gets the main string & the necessary params
 * to print a formatted str.
 * @format: str with all desired cahrs
 * Return: totoal count of the chars printed
 */

int _printf(const char *format, ...)
{
  int printed_chars;
  convert_t f_list[] ={
    {"c", print_char},
    {"s", print_string},
    {"%", print_percent},
    {"d", print_integer},
    {"i", print_integer},
    {"b", print_binary},
    {"r", print_reversed},
    {"R", rot13},
    {"u", unsigned_integer},
    {"o", print_octal},
    {"x", print_hex},
    {"X", print_hex},
    {NULL, NULL}
  };
  va_list arg_list;

  if (format == NULL)
    return (-1);

  va_start(arg_list, format);
  /*call parser func*/
  printed_chars = parser(format, f_list, arg_list);
  va_end(arg_list);
  return (printed_chars);
}
