#include "main.h"

int len_data(char c, handler_t *h, va_list arr)
{
	int ln, i;
	for (i = 0; i < 3; i++)
	{
		if (h[i].s == c)
		{
			ln = len(h[i].handler(arr));
			return (ln);
		}
	}
	return (0);
}

int specifyer_chck(const char *f)
{
	int chk, i;
	char formt [] = "cs%";

	chk = 0;
	while (*f)
	{
		for (i = 0; i < 3; i++)
		{
			if (*f == '%' && *++f == formt[i])
				chk++;
		}
		f++;
	}
	return (chk);
}

/**
 * _printf - Works as the printf function in C
 * @format: the first argument and the format string
 * @...: the rest of the argument
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list arr;
	const char *ptr, *p;
	char *buff, *spc;
	unsigned int j, k, l, chk, ln_format, ln_d, ln;

	handler_t fmt[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_p}
	};
	va_start(arr, format);
	chk = specifyer_chck(format);
	ln_format = len(format);

	spc = malloc(sizeof(char) * chk);
	for (ptr = format; *ptr; ptr++)
	{
		while (*ptr == '%')
		{	
			*spc++ = *++ptr;
		}
	}

	if (chk > 1)
	{
		ln_d = 0;
		for (j = 0; j < chk; j++)
			ln_d += len_data(spc[j], fmt, arr);
	}
	else if (chk == 1)
		ln_d = len_data(spc[0], fmt, arr);
	ln = (ln_format - chk) + ln_d;
	buff = malloc(sizeof(char) * ln);
	for (p = format; *p; p++)
	{
		while (*p != '%')
		{
			*buff++ = *p;
		}
		p++;
		k = 0;
		while (k < 3 && *p == fmt[k].s)
		{
			while (*fmt[k].handle)
			{
				*buff++ = fmt[k].handle++;
			}
		}
	}

	l = len(buff);
	write(0, buff, l);


	va_end(arr);
	return (l);
}
