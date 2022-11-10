#include "main.h"
/**
 * countdigit - count digit of a number
 * @nb: the number to count
 * Return: the number of digit
 */
int countdigit(int nb)
{
	int z, digit = 0;

	for (z = 0; nb != 0; z++)
	{
		nb /= 10;
		digit++;
	}
	return (digit);
}

/**
 * isnegative - check if number is negative if yes
 * @nb: the number to check
 * @digit: the digit
 * Return: the number but positive
 */
int isnegative(int nb, int *digit)
{
	char moins = 45;

	if (nb < 0)
	{
		if (nb == INT_MIN)
		{
			nb += 1;
			nb *= -1;
			*digit += write(1, &moins, 1);

		}
		else
		{
			nb *= -1;
			*digit += write(1, &moins, 1);
		}
	}
	return (nb);
}

/**
 * writemalloc - ecrit les dernier digit dans le malloc
 * @ptr: an address to a pointer
 * @nb: a number
 * Return: z.
 */
int writemalloc(int *ptr, int nb)
{
	int z;

	for (z = 0; nb != 0; z++)
	{
		ptr[z] = (nb % 10) + '0';
		nb /= 10;
	}
	return (z);

}
