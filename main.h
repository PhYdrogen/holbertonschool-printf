#ifndef MAIN_HEADER
#define MAIN_HERDER
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...);
typedef struct form
{
	char perc;
	void (*printformat)(va_list);
}fmt_t ;

#endif
