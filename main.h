#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>

/**
 * struct type - maps a conversion specifier to a handler
 * @specifier: conversion character
 * @fn: pointer to the function that prints it
 */

typedef struct type
{
	char specifier;
	int (*fn)(va_list *);
}
typeuh;

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list *args);
int print_string(va_list *args);
int print_percent(va_list *args);
int print_int(va_list *args);

#endif
