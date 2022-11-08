#include "main.h"

void print_char(va_list i)
{
	char b;

	b = va_arg(i, int);
	write(1, &b, 1);
}

void print_str(va_list i)
{
	int x = 0;
	char *b;

	b = va_arg(i, char *);
	while (b[x] != '\0')
		x++;
	write(1, b, x + 1);

}
void print_perc(va_list i)
{
	(void)i;
	write(1, "%", 1);
}

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
					x++;
					break;
				}
			}
			if (y==3)
			{
			write (1,"%",1); 
		        }
		}
		else if (format[x] == '\n')
		{
			write(1, "\n", 1);
			sortie++;
		}
		else
		{
			write(1, &format[x], 1);
			sortie++;
		}
		x++;
	}
	return (sortie);
}
