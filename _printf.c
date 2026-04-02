#include "main.h"

/**
 * handle_specifier - dispatches a supported conversion specifier
 * @spec: conversion character
 * @args: variadic list
 *
 * Return: chars printed for this specifier, 0 if unsupported, or -1 on error
 */
static int handle_specifier(char spec, va_list *args)
{
	typeuh types[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'\0', NULL}
	};
	int i;

	for (i = 0; types[i].specifier != '\0'; i++)
	{
		if (types[i].specifier == spec)
			return (types[i].fn(args));
	}
	return (0);
}

/**
 * _printf - produces output according to a format string
 * @format: format string with supported conversions (%c, %s, %%)
 *
 * Return: number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, count, written;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	count = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			written = _putchar(format[i]);
			if (written == -1)
			{
				va_end(args);
				return (-1);
			}
			count += written;
			continue;
		}

		i++;
		if (format[i] == '\0')
		{
			va_end(args);
			return (-1);
		}

		written = handle_specifier(format[i], &args);
		if (written == -1)
		{
			va_end(args);
			return (-1);
		}
		if (written == 0)
		{
			if (_putchar('%') == -1 || _putchar(format[i]) == -1)
			{
				va_end(args);
				return (-1);
			}
			count += 2;
		}
		else
		{
			count += written;
		}
	}

	va_end(args);
	return (count);
}
