#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len = 0;
	int len2 = 0;

	len = _printf("%c", 'S');
	len2 = printf("%c", 'S');
	printf("equart = %d %d\n", len, len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (3);
	}
	len = _printf("A char inside a sentence: %c. Did it work?\n", 'F');
	len2 = printf("A char inside a sentence: %c. Did it work?\n", 'F');
	printf("equart = %d %d\n", len, len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (4);
	}
	len = _printf("Let'see if the cast is correctly done: %c. Did it work?\n", 48);
	len2 = printf("Let'see if the cast is correctly done: %c. Did it work?\n", 48);
	printf("equart = %d %d\n", len, len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (5);
	}
	len = _printf("%s", "This sentence is retrieved from va_args!\n");
	len2 = printf("%s", "This sentence is retrieved from va_args!\n");
	fflush(stdout);
	printf("equart = %d %d\n", len, len2);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (6);
	}
	len = _printf("Complete the sentence: You %s nothing, Jon Snow.\n", "know");
	len2 = printf("Complete the sentence: You %s nothing, Jon Snow.\n", "know");
	printf("equart = %d %d\n", len, len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (7);
	}
	len = _printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
	len2 = printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
	printf("equart = %d %d\n", len, len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (8);
	}
	len = _printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
	len2 = printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
	printf("equart = %d %d\n", len, len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (9);
	}
	len = _printf("%%");
	len2 = printf("%%");
	printf("equart = %d %d\n", len, len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (10);
	}
	len = _printf("Should print a single percent sign: %%\n");
	len2 = printf("Should print a single percent sign: %%\n");
	printf("equart = %d %d\n", len, len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (11);
	}
	len = _printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
	len2 = printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
	printf("equart = %d %d\n", len, len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (12);
	}
	len = _printf("css%ccs%scscscs", 'T', "Test");
	len2 = printf("css%ccs%scscscs", 'T', "Test");
	printf("equart = %d %d\n", len, len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (13);
	}
	len = _printf(NULL);
	len2 = printf(NULL);
	printf("(NULL) equart = %d %d\n", len, len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (15);
	}
	len = _printf("%c", '\0');
	len2 = printf("%c", '\0');
	printf("equart = %d %d\n", len, len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (16);
	}
	len = _printf("%");
	len2 = printf("%");
	printf("equart = %d %d\n", len, len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (17);
	}
	len = _printf("%!\n");
	len2 = printf("%!\n");
	printf("( %! ) equart = %d %d\n", len, len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (18);
	}

	len = _printf("%K\n");
	len2 = printf("%K\n");
	printf("equart = %d %d\n", len, len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (19);
	}
	return (0);
}
