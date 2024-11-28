#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**                                                                                                                                 
 * main - Entry point                                                                                                              
 *                                                                                                                                 
 * Return: Always 0                                                                                                                 
 */
int print_char(int c)
{
  return write (1, &c, 1);
}

/**                                                                                                                                 
 * main - Entry point                                                                                                               
 *                                                                                                                                  
 * Return: Always 0                                                                                                                 
 */
int print_str(char *str)
{
  int count = 0;
  while (*str != '\0')
    {
      print_char(*str);
      ++count;
      ++str; 
    }
  return count; 
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
symbols = "0123456789abcdef";
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

/**
 * print_format - recognizes and converts given format
 * 
 * Return: Always 0
 */
int print_format(char specifier, va_list ap)
{
  int count = 0;

  switch (specifier)
    {
    case 'c':
      count += print_char(va_arg(ap, int));
    break;

    case 's':
      count += print_str(va_arg(ap, char *));
      break;

    case 'd':
      count += print_digit(va_arg(ap, int), 10);
      break;

    }
  return (0); 
}
