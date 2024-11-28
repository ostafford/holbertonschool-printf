# _printf

## main.h:
- Contains all function prototypes
- Includes necessary header files
- Helper functions (`handle_print`, `print_char`, `print_string`, `print_percent`, `print_int`, `print_digit`) handle specific types of format specifiers and their corresponding arguments.

<details>
  <summary>Function Prototype Explanation</summary>

```c
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


## _putchar.c:

- Contains the implementation of _putchar function
- Uses write system call to output characters

<details>
    <summary>Function Explanation</summary>

```c#
insert text here
```
</details>

## _printf.c:

- The function loops through `format` one character at a time.
- If it encounters a regular character (not `%`), it prints it directly.
- When `%` is found, the function looks at the next character to determine the format specifier
- Once specifier is confirmed the `handle_print` will be called to print the argment. 

<details>
    <summary>Function Explanation</summary>

```c
/* This function prints a formatted string and returns the total number of characters printed. */
int _printf(const char *format, ...)
{
    
    int i; /* Counter for going through the format string (character by character). */
    int printed_chars = 0;/* Counter for the total number of printed characters in terminal or post execution. */

    va_list list;/* Declares a `va_list` type variable (named 'list') to handle the variadic (multiple) arguments. */

    
    if (!format) /* "if 'format' is NOT a 'format' then it is a NULL */
        return (-1); /* Checks if the format string is NULL. If it is, return -1 (error). */
        /* This is here for a fail safe so the code doesn't crash. It will stop if statement is true. */

    
    va_start(list, format); /* Initializes (starts) the `va_list` to retrieve additional arguments passed to `_printf`. */

    
    for (i = 0; format[i] != '\0'; i++) /* Loops through each character in the format string. */
                                        /* It also excludes the last pointer  */
    {
        if (format[i] != '%') /* If the character is not a `%`, print it directly. */
        {
            putchar(format[i]); /* Calls `_putchar` to print the character to the console. */
            printed_chars++; /* Increment the printed characters counter. Essentially counting each character that gets printed.  */
            continue;   /* Skip the rest of the loop for this character. 
                        Once 'printed_chars' is complete continue will exit statement and execute 'va_end'*/
        }
        if (format[i + 1] == '\0')
            return (-1);/* If a `%` is found but there’s no specifier after it, return -1 (error). */
                        /* So essentially if there is a specifier that can't be determined process it as an error */

        printed_chars += handle_print(format, &i, list);
        /* Handles the formatted output. This function processes the `%` and its specifier,
           retrieves the corresponding argument, and prints it. 
           The number of printed characters is added to the total count. */

        /* This line of code increases the printed_chars value by the number of characters printed by handle_print.
        The handle_print function takes the format string, a pointer to the current index in the string, 
        and the variadic argument list (list).It processes the % specifier, retrieves the appropriate argument, 
        prints it, and returns the number of characters printed. */
    }
    
    va_end(list); /* Cleans up the `va_list` after use. */
    /* Think of you wiping the dinner table after eating your dinner. */

    return (printed_chars); /* Returns the total number of characters printed. */
}
```
</details>

## handle_print.c:

- Contains the logic for handling different format specifiers
- Uses a switch statement to route to appropriate print functions

<details>
    <summary>Function Explanation</summary>

```c#
insert text here
```
</details>

## print_functions.c:

- Contains individual functions for printing different types
- Each function handles a specific format specifier (c, s, %)

<details>
    <summary>Function Explanation</summary>

```c#
insert text here
```
</details>

## print_digit.c:

- print_int(): Gets an integer argument from va_list and passes it to print_number
- print_number(): Recursively prints an integer, handling:
    - Negative numbers (prints minus sign and converts to positive)
    - Multi-digit numbers (uses recursion to print each digit)
    - Returns count of characters printed

<details>
    <summary>Function Explanation</summary>

```c#
insert text here
```
</details>


