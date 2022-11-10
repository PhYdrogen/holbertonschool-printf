#include "main.h"
/**
 * print_char - blb
 * @i: all the word behin ,
 * Return: counter
 */
int print_char(va_list i)
{
	char b;

	b = va_arg(i, int);
	write(1, &b, 1);
	return (1);
}
/**
 * print_str - blb
 * @i: all the word behin ,
 * Return: counter
 */
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
/**
 * print_perc - blb
 * @i: all the word behin ,
 * Return: counter
 */
int print_perc(va_list i)
{
	(void)i;
	write(1, "%", 1);
	return (1);
}
/**
 * print_int - blb
 * @i: all the word behin ,
 * Return: counter
 */
int print_int(va_list i)
{
	int nb = 0, digit = 0, *y, z = 0, j = 0, negative = 0, flag = 0;

	nb = va_arg(i, int);
	nb = isnegative(nb, &negative, &flag);
	if (nb == 0)
		return (write(1, "0", 1));

	digit += countdigit(nb);

	y = malloc(1 + (sizeof(int) * digit));
	if (!y)
		exit(99);

	z = writemalloc(y, nb);
	nb = 0;
	for (j = (z - 1); nb < digit; j--)
	{
		if (flag == 1 && j == 0)
		{
			y[j] += 1;
			flag--;
		}
		write(1, &y[j], 1);
		nb++;
	}
	digit += negative;
	free(y);
	return (digit);
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
		{'i', print_int},
		{'d', print_int},
		{0, NULL}
	};
	int y = 0, sortie = 0;

	for (y = 0; fmt[y].perc != 0; y++)
	{
		if (format[*x + 1] == '\0')
			return (-1);

		else if (format[*x + 1] == fmt[y].perc)
		{
			sortie += fmt[y].printformat(liste);
			x++;
			break;
		}
	}
	if (fmt[y].perc == 0)
	{
		write(1, format, 1);
		write(1, &format[*x + 1], 1);
		sortie += 2;
	}
	return (sortie);
}
