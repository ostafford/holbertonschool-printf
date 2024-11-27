#include "main.h"

/**
 * Prints a single character
 * @c: Character to print
 *
 * Return: Number of characters printed
 */
int print_char(char c)
{
    return (write(1, &c, 1));

}

/**
 * Prints a string
 * @str: String to print
 *
 * Return: Number of characters printed
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

}