#include <unistd.h>
#include "main.h"

/**
 * print_char - prints a character
 * @args: variadic list
 *
 * Return: number of characters printed
 */
int print_char(va_list *args)
{
	char c;

	c = (char)va_arg(*args, int);
	return (_putchar(c));
}

/**
 * print_string - prints a string
 * @args: variadic list
 *
 * Return: number of characters printed
 */
int print_string(va_list *args)
{
	char *s;
	int i;

	s = va_arg(*args, char *);
	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
	{
		if (_putchar(s[i]) == -1)
			return (-1);
	}
	return (i);
}

/**
 * print_percent - prints a percent sign
 * @args: unused variadic list
 *
 * Return: number of characters printed
 */
int print_percent(va_list *args)
{
	(void)args;
	return (_putchar('%'));
}
