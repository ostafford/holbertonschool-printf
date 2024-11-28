#include "main.h"

/**
 * handle_print - Prints an argument based on its type
 * @format: Formatted string
 * @i: Index of current character
 * @list: List of arguments
 * Return: Number of chars printed
 */
int handle_print(const char *format, int *i, va_list list)
{
int printed_chars = 0;

(*i)++; /* Move past the % */

switch (format[*i])
{
case 'c':
printed_chars += print_char(list);
break;

case 's':
printed_chars += print_string(list);
break;

case '%':
printed_chars += print_percent();
break;

case 'd':
case 'i':
printed_chars += print_int(list);
break;

default:
/* Handle unknown specifier */
_putchar('%');
_putchar(format[*i]);
printed_chars += 2;
break;

}
return (printed_chars);
}
