#include "main.h"
#include <stdio.h>

/* Function Prototype */


/* Data Segment */

/* BSS Segment */

/* Stack */


/* Text Segment */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");

    
    return (0);
}