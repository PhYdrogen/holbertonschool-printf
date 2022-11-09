#include "main.h"

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
		{'%', print_perc},
		{0, NULL}
	};
	va_list liste;
	int x = 0, y = 0, sortie = 0;

	if (!format)
		return (-1);
	va_start(liste, format);
	while (format[x] != '\0')
	{
		if (format[x] == '%')
		{
			for (y = 0; fmt[y].perc != 0; y++)
			{
				if (format[x + 1] == '\0')
					return (-1);

				else if (format[x + 1] == fmt[y].perc)
				{	sortie += fmt[y].printformat(liste);
					x++;
					break;
				} }
			if (fmt[y].perc == 0)
			{	fmt[2].printformat(liste);
				sortie++;
			} }
		else if (format[x] == '\n')
		{	write(1, "\n", 1);
			sortie++;
		} else
		{	write(1, &format[x], 1);
			sortie++;
		}	x++;
	}	va_end(liste);
	return (sortie);
}
