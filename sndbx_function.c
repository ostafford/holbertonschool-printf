#include "main.h"

/**
 * _printf - Produces output according to a specific format
 * - Parses the `format` string.
 * - Supported specifiers (`%c`, `%s`, `%%`).
 * Return:
 * - Total number of characters written to stdout.
 * - Returns -1 if `format` is NULL or if there is an error.
 */
int _printf(const char *format, ...)
{
    va_list args; /* variable list created to store input arguments */
    int i = 0, /* index counter (iterator) for the format string */
    count = 0; /* records the value of characters printed (stdout) */

    if (!format || *format == '\0')
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%') /* Check for format specifier */
        {
            i++;
            if (!format[i]) /* Handle dangling % at the end */
                return (-1);

            if (format[i] == 'c') /* Handle character specifier */
                count += print_char(va_arg(args, int));
            else if (format[i] == 's') /* Handle string specifier */
                count += print_string(va_arg(args, char *));
            else if (format[i] == '%') /* Handle %% */
                count += write(1, "%", 1);
            else
                return (-1); /* Unknown specifier */
        }
        else /* Regular character */
            count += write(1, &format[i], 1);

        i++;
    }

    va_end(args);
    return (count);
}


/**
 * print_char - Writes a single character to stdout
 * Description:
 * - Uses the `write` system call to output the character.
 * - used within `_printf` when `%c` format specifier is called.
 * Return:
 * - 1 (always), as only one character is printed.
 * Essentially this is our own version of 'putchar'
 */
int print_char(char c)
{
    return (write(1, &c, 1));
    /** write = write data thats passed 
    *   1 = value of stdout. write to standard output
    *   &c = is the pointer for the specifier '%c'
    *   1 = byte value. How much memory does it take. 
    */
}


/**
 * print_string - Writes a string to stdout
 * Pointer to the null-terminated string to print.
 * - Loops through each character in the string and writes it to stdout.
 * - Handles the case where `str` is NULL by printing "(null)" instead.
 *
 * Return:
 * - Total number of characters printed.
 */
int print_string(const char *str)
{
    int count = 0;

    if (!str)
        str = "(null)";

    while (*str)
    {
        count += write(1, str, 1);
        str++;
    }

    return (count);
    /* if the string is NOT a string print (null) as a fail safe indicating its not a string
        - iterate (move along each character) the character of the string
        - write (print) each character to stdout (terminal)
        - move the pointer str++ one character per loop
        - once all characters written return total number of characters written
     */
}
