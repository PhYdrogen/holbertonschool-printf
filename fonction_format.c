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
* print_int - print integer
* @i: all the word behin ,
* Return: counter
*
*/
int print_double(va_list valist)
{
	int i, div, len;
	unsigned int num;
	i = va_arg(valist,int);
	div = 1;
	len = 0;
	char c;
	if (i < 0)
	{
		num = i * -1;
		c = '-';
		len += write(1, &c, 1);
	}
	else
	{
		num = i;
	}
	for (; num/div > 9;)
	{
		div *= 10;
	}
	for (; div != 0;)
	{
		c = '0' + (num /div);
	 	len += print_char(&c);
		num %= div;
		div /=10;
	}
	return len;
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
		{'i', print_double},
		{'d', print_double},
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
