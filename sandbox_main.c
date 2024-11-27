#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/* Function Prototype */
int _printf(const char *format, ...);

/* Data Segment */

/* BSS Segment */

/* Stack */
int _printf(const char *format, ...)
{
    /* va_list to check multiple arguments
    `char_counter` records how many characters are printed*/
    va_list args;
    int char_counter = 0;

    /* Before continuing the execution if format fails (NULL)
    print error message*/
    if (format == NULL)
    {
        printf("DEBUG: Format is NULL\n");
        return (-1);
    }

/* Starts the variable argument list 
So essentially starting what has been passed through as arguments*/
    va_start(args, format);

    /* Loop through each character in the format string */
    while (*format)
    {
        printf("DEBUG: Current format character = '%c'\n", *format);
        /* If it has the format specifier continue with the switch statements c, s, % */
        if (*format == '%')
        {
            format = format + 1;
            if (*format == '\0')
            {
                printf("DEBUG: Found '%%' but no specifier after it!\n");
                va_end(args);
                return(-1);
            }
            /* ++ allows the if statement to move along the string by 1 character */
            printf("DEBUG: Found specifier '%%%c'\n", *format);
            switch (*format)
            {
                case 'c':
                    printf("DEBUG: Printing character '%c'\n", c);
                    putchar((char)va_arg(args, int));
                    char_counter = char_counter + 1;
                    break;
                   
                case 's': {
                    char *str = va_arg(args, char *);
                    if (str != NULL)
                {
                     /* this is the case for the string method. 
                    if str is not NULL then continue.
                    while *str is getting each character checked it will print each character as a string hence the *str++.
                    else if it is a NULL string to print the null message. */
                        printf("DEBUG: Printing string '%s'\n", str);
                        while (*str)
                        {
                            putchar(*str++);
                            char_counter = char_counter + 1;
                        }
                    }
                    else
                    {
                        /* the value of char_count is now the error message due to the encounter */
                         printf("DEBUG: Printing (null)\n");
                        char_counter += _printf("**ERROR** --| STRING HANDLE ERROR |-- **ERROR**\n");
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
            char_counter++;
        }
        format++;
    }

    va_end(args);

    return char_counter;
}

/* Text Segment */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    _printf(NULL);
    _printf("H%!@#$^&*()\n",'h');
    _printf("%");

    _printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    len = _printf("Percent:[%%]\n");

    return (0);
}