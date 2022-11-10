#ifndef MAIN_HEADER
#define MAIN_HEADER
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

typedef struct form
{
	char perc;
	int (*printformat)(va_list);
} fmt_t;

int _printf(const char *format, ...);
int print_char(va_list i);
int print_str(va_list i);
int print_perc(va_list i);
int verif_next_char(const char *format, va_list i, int *x);
int countdigit(int nb);
int isnegative(int nb, int *digit);
int writemalloc(int *ptr, int nb);
#endif
