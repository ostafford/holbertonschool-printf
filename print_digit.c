#include "main.h"

/**
 * print_int - Prints an integer
 * @types: List of arguments
 * Return: Number of chars printed
 */
int print_int(va_list types)
{
    int n = va_arg(types, int);
    return (print_digit(n));
}

/**
 * print_digit - Prints a number
 * @n: Number to be printed
 * Return: Number of chars printed
 */
int print_digit(int n)
{
    int count = 0;
    unsigned int num;

    if (n < 0)
    {
        _putchar('-');
        count++;
        num = -n;
    }
    else
        num = n;

    if (num / 10)
        count += print_digit(num / 10);

    _putchar((num % 10) + '0');
    count++;

    return (count);
}