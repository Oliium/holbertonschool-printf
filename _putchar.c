#include <unistd.h>

/**
 * _putchar - writes a character to stdout
 * @c: character to print
 *
 * Return: 1 on success, -1 on failure
 */
int _putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}
