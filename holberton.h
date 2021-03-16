#ifndef PRINT_F
#define PRINT_F

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 *struct convert - defines the symbols and functions structures
 *
 *@sym: operator
 *@f: associated function
 */

struct convert
{
  char *sym;
  int (*f)(va_list);
};
typedef struct convert convert_t;

/*Main functions*/
int _printf(const char *format, ...);
int parser(const char *format, convert_t f_list[], va_list arg_list);
int _write_char(char);
int print_number(va_list args);
int print_unsgined_number(unsigned int n);
int print_reversed(va_list arg);
int rot13(va_list list);
int print_char(va_list);
int print_string(va_list);
int print_percent(va_list);
int print_integer(va_list);
int print_number(va_list);
int print_binary(va_list);
int unsigned_integer(va_list);
int print_octal(va_list list);
int print_hex(va_list list);
int print_heX(va_list list);

/*helper functions*/
unsigned int base_len(unsigned int, int);
char *rev_string(char *);
void write_base(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);
int print_unsgined_number(unsigned int);

#endif
