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

/**            
 * print_digit 
 *
 * Return:
 */
int print_digit(long n, int base)
{
int count;
char *symbols;
symbols = "0123456789";
if (n < 0)
{
write (1, "-", 1);
return print_digit(-n, base) +1;
}
else if (n < base)
return print_char(symbols[n]);
else
{
count = print_digit(n / base, base);
return count + print_digit(n % base, base);
}
}
