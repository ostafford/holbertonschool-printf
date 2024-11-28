#include "main.h"

/**
 * _printf - Printf function
 * @format: format string
 * Return: Printed chars
 */
int _printf(const char *format, ...)
{
int i;
int printed_chars = 0;
va_list list;

if (!format)
return (-1);

va_start(list, format);

for (i = 0; format[i] != '\0'; i++)
{
if (format[i] != '%')
{
_putchar(format[i]);
printed_chars++;
continue;
}

if (format[i + 1] == '\0')
return (-1);

printed_chars += handle_print(format, &i, list);
}

va_end(list);
return (printed_chars);
}
