#include "main.h"

#define UNSUPPORTED_SPECIFIER (-2)

/**
 * handle_specifier - dispatches a supported conversion specifier
 * @spec: conversion character
 * @args: variadic list
 *
 * Return: chars printed for this specifier, -2 if unsupported, or -1 on error
 */
static int handle_specifier(char spec, va_list *args)
{
	specifier_func types[] = {
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
	return (UNSUPPORTED_SPECIFIER);
}

/**
 * print_unknown_specifier - prints '%' and unsupported specifier
 * @spec: unsupported conversion character
 * @count: total printed characters
 *
 * Return: 0 on success, -1 on error
 */
static int print_unknown_specifier(char spec, int *count)
{
	if (_putchar('%') == -1 || _putchar(spec) == -1)
		return (-1);
	*count += 2;
	return (0);
}

/**
 * process_directive - handles one conversion directive after '%'
 * @format: format string
 * @i: current index in format string
 * @args: variadic list
 * @count: total printed characters
 *
 * Return: 0 on success, -1 on error
 */
static int process_directive(const char *format, int *i,
		va_list *args, int *count)
{
	int written;

	(*i)++;
	if (format[*i] == '\0')
		return (-1);
	written = handle_specifier(format[*i], args);
	if (written == -1)
		return (-1);
	if (written == UNSUPPORTED_SPECIFIER)
		return (print_unknown_specifier(format[*i], count));
	*count += written;
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
	int i;
	int count;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	count = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			if (_putchar(format[i]) == -1)
			{
				va_end(args);
				return (-1);
			}
			count++;
			continue;
		}
		if (process_directive(format, &i, &args, &count) == -1)
		{
			va_end(args);
			return (-1);
		}
	}

	va_end(args);
	return (count);
}
