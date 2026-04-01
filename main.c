#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

/**
 * struct type - Structure that has the map to specifiers with a function
 * @specifier: Specifier that can be triggered
 * @fn: function that points to other printable functions
 */
typedef struct type
{
	char specifier;
	int (*fn)(va_list *);
} typeuh;

int _printf(const char *format, ...);
int _putchar(char c);

#endif
