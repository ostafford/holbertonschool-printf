#include "main.h"

/**
 * _printf - reinventing the printf function
 * @format: The format string that controls the output
 * This function works similarly to the standard printf function,
 * with custom handling of format specifiers.
 * Required support `%c` `%s` `%%`.
 * If the format string is NULL, it prints an error message.
 * Return: The number of characters printed (excluding the null byte).
 * If the format is NULL, returns -1.
 */

int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;

    if (!format || *format == '\0')
        return (-1);  

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%') 
        {
            i++;  
            if (format[i] == '%')  
            {
                count += write(1, "%", 1); 
            }
            else if (format[i] == 'c')  
            {
                count += print_char(va_arg(args, int));
            }
            else if (format[i] == 's') 
            {
                count += print_string(va_arg(args, char *));
            }
            else  
            {
                return (-1);  
            }
        }
        else  
        {
            count += write(1, &format[i], 1);
        }
        i++;
    }

    va_end(args);

    return (count);
}

