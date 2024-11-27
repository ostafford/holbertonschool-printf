#include "main.h"

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
_printf("Length:[%d, %i]\n", len, len);
_printf("Negative:[%d]\n", -762534);

_printf("Character:[%c]\n", 'H');
_printf("String:[%s]\n", "I am a string !");
len = _printf("Percent:[%%]\n");

return (0);
}
