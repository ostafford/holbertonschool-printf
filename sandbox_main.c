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
    if (format == NULL){
    _printf("**ERROR** --| NOT A VALID STRING INPUT!! |-- **ERROR** \n");
        return -1;
    }

/* Starts the variable argument list 
So essentially starting what has been passed through as arguments*/
    va_start(args, format);

    /* Loop through each character in the format string */
    while (*format)
    {
        /* If it has the format specifier continue with the switch statements c, s, % */
        if (*format == '%')
        {
            /* ++ allows the if statement to move along the string by 1 character */
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
                     /* this is the case for the string method. 
                    if str is not NULL then continue.
                    while *str is getting each character checked it will print each character as a string hence the *str++.
                    else if it is a NULL string to print the null message. */
                        while (*str)
                        {
                            putchar(*str++);
                            char_counter = char_counter + 1;
                        }
                    }
                    else
                    {
                        /* the value of char_count is now the error message due to the encounter */
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

    _printf(NULL);
    _printf("H%!@#$^&*()\n",'h');

    _printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    len = _printf("Percent:[%%]\n");

    return (0);
}