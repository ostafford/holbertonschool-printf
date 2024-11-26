#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * 
 *
 *
 */
 int _printf(const char *format, ...)
 {
 va_list ap;
 int count = 0;

va_start(ap, format);

while (*format != '\0')
{
if (*format == '%')
count += print_format(*(++format), ap);
 else
   count += write(1, format, 1); 
++format; 
}
va_end (ap); 
return count;
}
