#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/* Function prototypes */
int _printf(const char *format, ...);
int handle_print(const char *format, int *i, va_list list);
int print_char(va_list types);
int print_string(va_list types);
int print_percent(void);

/* Helper function prototype */
int _putchar(char c);

#endif /* MAIN_H */