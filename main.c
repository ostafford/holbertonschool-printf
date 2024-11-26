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
  int count;

  count = _printf("Hello %s\n", "John");
  _printf("This shit working? %s\n", count); 
}
