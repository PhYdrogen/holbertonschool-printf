#include "main.h"

/**
 * _printf - print to stdout
 * @format: the string as
 * Return: number of char printed
 */
int _printf(const char *format, ...)
{
	va_list liste;
	int x = 0, sortie = 0, fonctionreturn = 0;
	int *ptrX;

	ptrX = &x;
	if (!format)
		return (-1);

	va_start(liste, format);

	while (format[x] != '\0')
	{
		if (format[x] == '%')
		{
			fonctionreturn = verif_next_char(format, liste, ptrX);
			if (fonctionreturn == (-1))
				return (-1);
			sortie += fonctionreturn;
			x++;
		}
		else
		{
			write(1, &format[x], 1);
			sortie++;
		}
		x++;
	}
	va_end(liste);
	return (sortie);
}
