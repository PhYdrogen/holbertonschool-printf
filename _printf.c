#include "main.h"

void print_char(va_list i);

void print_str(va_list i);

void print_perc(va_list i);

/**
 * _printf - print to stdout
 * @format: the string as
 * Return: number of char printed
 */
int _printf(const char *format, ...)
{
	fmt_t fmt[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_perc}
	};
	va_list(liste);
	int x = 0, y = 0, sortie = 0;

	va_start(liste, format);

	while (format[x] != '\0')
	{
		if (format[x] == '%')
		{
			for (y = 0; y < 3; y++)
			{
				if (format[x + 1] == fmt[y].perc)
				{
					fmt[y].printformat(liste);
					sortie++;
				}
			}
		}
		else if (format[x] == '\n')
		{

		}
	}
	return (sortie);
}
