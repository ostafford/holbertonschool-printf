# _printf

### main.h:

- Contains all function prototypes
- Includes necessary header files
- Helper functions (`handle_print`, `print_char`, `print_string`, `print_percent`, `print_int`, `print_digit`) handle specific types of format specifiers and their corresponding arguments.

<details>
  <summary>Function Prototype Explanation</summary>

```c#
int _printf(const char *format, ...);
/* 
 * - 'const char *format' -> A constant character pointer to the format string
 * - '...' -> A variadic parameter allowing multiple arguments
 */

int handle_print(const char *format, int *i, va_list list);
/*
 * 'const char *format' -> Pointer to the format string
 * '*i' -> Pointer to the current index being processed in the format string
 * 'va_list list' -> holding the variadic arguments (multiple arguments) that are passed to _printf
 */

int print_char(va_list types);
/*
 * 'types' -> A list containing the character to print.
 */

int print_string(va_list types);
/* 
 * 'va_list types' -> A list containing the string to print.
 */

int print_percent(void);
/* 
 * 'void' -> Prints the '%' character itself. This is used when the format string contains %%
 */

int print_int(va_list types);
/* 
 * 'va_list types' -> A list containing the integer to print.
 */

int print_digit(int d);
/* 
 * 'int d' -> The digit to print as an integer (0-9)
 */
```
</details>


### _putchar.c:

- Contains the implementation of _putchar function
- Uses write system call to output characters

<details>
    <summary>Code Explanation</summary>

```c#
insert text here
```
</details>

### _printf.c:

- Contains the main _printf function
- Handles the basic parsing of the format string
- Delegates specific format specifiers to handle_print

<details>
    <summary>Code Explanation</summary>

```c#
insert text here
```
</details>

### handle_print.c:

- Contains the logic for handling different format specifiers
- Uses a switch statement to route to appropriate print functions

<details>
    <summary>Code Explanation</summary>

```c#
insert text here
```
</details>

### print_functions.c:

- Contains individual functions for printing different types
- Each function handles a specific format specifier (c, s, %)

<details>
    <summary>Code Explanation</summary>

```c#
insert text here
```
</details>

### print_numbers.c:

- print_int(): Gets an integer argument from va_list and passes it to print_number
- print_number(): Recursively prints an integer, handling:
    - Negative numbers (prints minus sign and converts to positive)
    - Multi-digit numbers (uses recursion to print each digit)
    - Returns count of characters printed

<details>
    <summary>Code Explanation</summary>

```c#
insert text here
```
</details>


