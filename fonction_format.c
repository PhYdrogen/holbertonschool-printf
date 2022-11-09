#include "main.h"

int print_char(va_list i)
{
	char b;

	b = va_arg(i, int);
	write(1, &b, 1);
	return (1);
}

int print_str(va_list i)
{
	int x = 0;
	char *b;

	b = va_arg(i, char *);

	if (b == NULL)
	{
		b = "(null)";
	}

	while (b[x] != '\0')
		x++;

	write(1, b, x);
	return (x);
}

int print_perc(va_list i)
{
	(void)i;
	write(1, "%", 1);
	return (1);
}
/**
 * verif_next_char - c'est une compression de code car la function
 * fait plus de 40 lignes
 * @format: le string initial
 * @liste: la liste passé par valeur
 * @x: le nombre auquel on est
 * Return: le nombre qu'il aura calculer
 */
int verif_next_char(const char *format, va_list liste, int *x)
{
	fmt_t fmt[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_perc},
		{0, NULL}
	};
	int y = 0, sortie = 0, cpX = 0;

	cpX = *x;
	for (y = 0; fmt[y].perc != 0; y++)
	{
		if (format[cpX + 1] == '\0')
			return (-1);

		else if (format[cpX + 1] == fmt[y].perc)
		{
			sortie += fmt[y].printformat(liste);
			x++;
			break;
		}
	}
	if (fmt[y].perc == 0)
	{
		fmt[2].printformat(liste);
		sortie++;
	}
	return (sortie);
}
