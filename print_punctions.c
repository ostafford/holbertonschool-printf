#include "main.h"

/**
 * print_char - Prints a char
 * @types: List of arguments
 * Return: Number of chars printed
 */
int print_char(va_list types)
{
char c = va_arg(types, int);
return (_putchar(c));
}

/**
 * print_string - Prints a string
 * @types: List of arguments
 * Return: Number of chars printed
 */
int print_string(va_list types)
{
int length = 0;
char *str = va_arg(types, char*);

if (!str)
str = "(null)";

while (str[length] != '\0')
{
_putchar(str[length]);
length++;
}

return (length);
}

/**
 * print_percent - Prints a percent sign
 * Return: Number of chars printed
 */
int print_percent(void)
{
_putchar('%');
return (1);
}
