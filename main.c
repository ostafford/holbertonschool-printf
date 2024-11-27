#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/* Function Prototype */
int _printf(const char *format, ...);

/* Data Segment */

/* BSS Segment */

/* Stack */


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