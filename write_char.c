#include "holberton.h"

/**
 * _write_char - write to stdout
 * @c: charter to print
 * Return: 1 if successful
 * -1 on error
 */

int _write_char(char c)
{
  return (write(1, &c, 1));
}
