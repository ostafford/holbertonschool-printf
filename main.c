#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
  char array[] = "doo doo";

  _printf("Hello %s\n", "John");
  _printf("Easy, Easy %d, what's good gangsta %s\n", 215, array);
  _printf("%d\n", 123123123);
  
  return (0); 
}
