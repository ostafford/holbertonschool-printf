#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - reinventing the printf function
 * @format: The format string that controls the output
 * This function works similarly to the standard printf function,
 * with custom handling of format specifiers.
 * Required support `%c` `%s` `%%`.
 * If the format string is NULL, it prints an error message.
 * Return: The number of characters printed (excluding the null byte).
 *         If the format is NULL, returns -1.
 */

int _printf(const char *format, ...)
{
va_list args;
int char_counter = 0;
if (format == NULL)
{
_printf("**ERROR** --| NOT A VALID STRING INPUT!! |-- **ERROR** \n");
return (-1);
}
va_start(args, format);
while (*format)
{
if (*format == '%')
{
format = format + 1;
switch (*format)
{
case 'c':
putchar((char)va_arg(args, int));
char_counter = char_counter + 1;
break;
case 's': {
char *str = va_arg(args, char *);
if (str != NULL)
{
while (*str)
{
putchar(*str++);
char_counter = char_counter + 1;
}
}
else
{
char_counter += _printf("(null)");
}
break;
}
case '%':
putchar('%');
char_counter = char_counter + 1;
break;
default:
_printf("**ERROR** |-- UNKNOWN FORMAT SPECIFIER --| **ERROR**\n");
break;
}
}
else
{
putchar(*format);
char_counter = char_counter + 1;
}
format++;
}
va_end(args);
return (char_counter);
}
