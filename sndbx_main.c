#include "main.h"

/* Function Prototype */
int _printf(const char *format, ...);
int print_char(char c);
int print_string(const char *str);

/* Data Segment */

/* BSS Segment */

/* Stack */

/* Text Segment */
int main(void)
{
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');

    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");

    _printf("Percent:[%%]\n");
    printf("Percent:[%%]\n");

    return (0);
}