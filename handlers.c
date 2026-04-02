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

/**
 * print_int - prints a signed integer
 * @args: variadic list
 *
 * Return: number of characters printed
 */
int print_int(va_list *args)
{
	int num = va_arg(*args, int);
	long num_long = num;
	int count = 0;
	long temp;
	int digits;
	long divisor;
	int i;

	if (num_long == 0)
	{
		return (_putchar('0'));
	}

	if (num_long < 0)
	{
		if (_putchar('-') == -1)
			return (-1);
		count++;
		num_long = -num_long;
	}

	/* Calculate number of digits */
	temp = num_long;
	digits = 0;
	while (temp > 0)
	{
		digits++;
		temp /= 10;
	}

	/* Print digits from left to right */
	divisor = 1;
	for (i = 1; i < digits; i++)
		divisor *= 10;

	for (i = 0; i < digits; i++)
	{
		char digit = '0' + (num_long / divisor);
		if (_putchar(digit) == -1)
			return (-1);
		count++;
		num_long %= divisor;
		divisor /= 10;
	}

	return (count);
}
