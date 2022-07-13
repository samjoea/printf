#include "main.h"

/**
 *
 */
int len(char *s)
{
	if (*s)
		return (1 + len(s + 1));
	return (0);
}

char *str_c(char *s, char *p)
{
	int i;

	for (i = 0; *s && s[i]; i++)
	{
		p[i] = s[i];
	}
	return (p);
}

char *print_char(va_list arr)
{
	char *s, c;

	s = malloc(sizeof(char) * 2);
	if (s == NULL)
		return (NULL);
	c = va_arg(arr, int);
	if (c == 0)
		c = '\0';
	s[0] = c;
	s[1] = '\0';
	return (s);
}

char *print_str(va_list arr)
{
	int ln;
	char *s, *str;

	s = va_arg(arr, char *);
	ln = len(s);
	str = malloc(sizeof(char) * ln);
	if (str == NULL)
		return (NULL);
	return (str_c(s, str));
}

char *print_p(va_list arr)
{
	char *p, c;

	c = va_arg(arr, int);
	p = malloc(sizeof(char) * 2);
	if (p == NULL)
		return (NULL);
	c = '%';
	p[0] = c;
	p[1] = '\0';

	return (p);
}
