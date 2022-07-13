#ifndef PRINTF_H
#define PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * struct format - a format template
 * @s: a character of the specified format
 * @handle: a function pointer to a handler
 */
typedef struct format
{
	char s;
	char (*handle)(va_list);

} handler_t;

int _printf(const char *format, ...);
char *print_char(va_list);
char *print_str(va_list);
char *print_p(va_list);
int len(char *);
char *str_c(char *, char *);
int len_data(char *, handler_t, va_list);
int specifyer_chck(char *);
#endif
