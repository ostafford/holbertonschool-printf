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
unsigned int ui;

_printf("Character:[%c]\n", 'H');
_printf("String:[%s]\n", "I am a string !");
_printf("Percent:[%%]\n");
_printf("hello %s\n", "world", 1, 2, 3, 4);

_printf("Length:[%d, %i]\n", len, len);
_printf("Negative:[%d]\n", -762534);
_printf("Len:[%d]\n", len);


return (0);
}
