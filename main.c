#include "main.h"
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...);

/**
 * main - Entry point for the program
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
int len;
int len2;

_printf(NULL);
_printf("H%!@#$^&*()\n", 'h');
_printf("%");

_printf("Character:[%c]\n", 'H');
_printf("String:[%s]\n", "I am a string !");
len = _printf("Percent:[%%]\n");

return (0);
}
