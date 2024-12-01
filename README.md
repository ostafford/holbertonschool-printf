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
 * - 'const char *format'   -> A constant character pointer to the format string
 * - '...'                  -> A variadic parameter allowing multiple arguments
 */

int handle_print(const char *format, int *i, va_list list);
/*
 * 'const char *format' -> Pointer to the format string
 * '*i'                 -> Pointer to the current index being processed in the format string
 * 'va_list list'       -> holding the variadic arguments (multiple arguments) that are passed to _printf
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
- Uses `write` system call to output characters (`unistd.h`)

<details>
    <summary>Function Explanation</summary>

```c
int _putchar(char c)
/* 
 * 'int'      -> This is the return type, indicating the function will return an integer.
 * '_putchar' -> The name of the function (you can call it anything you want, but '_putchar' is conventional for this purpose).
 * '(char c)' -> The parameter 'c', of type 'char', representing the character to print.
 *               (You can choose a different name for the parameter, but 'c' is short and common for this use.)
 */
{
return (write(1, &c, 1));
/*
 * 'return' ->  Returns (does not print) the result of the 'write' call.
 *              - If successful, it returns '1' (1 character written).
 *              - If an error occurs, it returns '-1'.
 * 'write'  ->  A system call that writes data directly to a file descriptor.
 *              (What's a 'file descriptor'? Think of it as a sticky note where the number
 *              identifies a specific file or output device.)
 * '1'      ->  Represents the file descriptor for standard output ('stdout').
 * '&c'     ->  A 'pointer' to the memory location of the character 'c'.
 * '1'      ->  The number of bytes to write. Since a 'char' is 1 byte, this specifies
 *              writing exactly 1 character.
 */
}

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
    
    int i;                  /* Counter for going through the format string (character by character). */
    int printed_chars = 0;  /* Counter for the total number of printed characters in terminal or post execution. */

    va_list list;/* Declares a `va_list` type variable (named 'list') to handle the variadic (multiple) arguments. */

    
    if (!format)        /* "if 'format' is NOT a 'format' then it is a NULL */
        return (-1);    /* Checks if the format string is NULL. If it is, return -1 (error). */
                        /* This is here for a fail safe so the code doesn't crash. It will stop if statement is true. */

    
    va_start(list, format); /* Initializes (starts) the `va_list` to retrieve additional arguments passed to `_printf`. */

    
    for (i = 0; format[i] != '\0'; i++) /* Loops through each character in the format string. */
                                        /* It also excludes the last pointer  */
    {
        if (format[i] != '%') /* If the character is not a `%`, print it directly. */
        {
            putchar(format[i]); /* Calls `_putchar` to print the character to the console. */
            printed_chars++;    /* Increment the printed characters counter. Essentially counting each character that gets printed.  */
            continue;           /* Skip the rest of the loop for this character. 
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
    
    va_end(list);   /* Cleans up the `va_list` after use. */
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
int handle_print(const char *format, int *i, va_list list)
/*  'handle_print'              -> takes three parameters. 
 *  'format' (string pointer)   -> This is a pointer to a string containing placeholders (%c, %s, etc.) and any fixed text.
 *  'i' (integer pointer)       -> A pointer to an integer that keeps track of the current index in the format string  
 *  'va_list'                   -> A 'special type' used to access the variable arguments provided to the function
 *
 *  Example:    Function will receive instructions (placeholders)on what to print ('format').
 *              To keep track of where you are with your instructions 'i' will indicates this.
 *              and 'va_list' will provide you with the values (arguments) needed. 
 */
{
int printed_chars = 0; /* Tracks the total amount of character printed */

(*i)++; /* Move past the '%' operator */

switch (format[*i]) /* The switch statement checks the character immediately after the '%' operator
                     * to determine what type of argument to process. 
                     *
                     * Eg. %c , %d , %i , etc
                     */
{
case 'c':
printed_chars += print_char(list);
break;

case 's':
printed_chars += print_string(list);
break;

case '%':
printed_chars += print_percent();
break;

case 'd':
case 'i':
printed_chars += print_int(list);
break;
/*  'case'          ->  name of the case to execute. 
 *                      (if the character immediately after the '%' matches execute this case block.)
 *  'printed_chars' ->  variable that is used to record the total amount of characters printed so far.
 *  '+='            ->  shorthand operator to add the value on the right side of the '=' back to the left side variable
 *                      eg. [printed_chars = printed_chars + print_char(list);]
 *  'print_char'    -> a function that accesses an argument from a 'list' and prints it (also returns the number of char printed (1))
 *  'print_string'  -> a function that accesses an argument from a 'list' and prints it (this will print the string "insert text here")
 *  'print_percent' -> a function that accesses an argument and prints the literal '%' symbol.
 *  'print_int'     -> a function that accesses an argument from a 'list' and prints an integer argument.
 *
 *  'list'          -> is a special type 'va_list' that handles multiple arguments. 
 *  'break'         -> is used to exit the switch statement after execution.
 *                     if there is no 'break' the function will continue through all possible switch cases (called a "fall through").
 */

default:
/* Handle unknown specifier [FAIL SAFE]*/
_putchar('%');
_putchar(format[*i]);
printed_chars += 2;
break;
/*  'default'               ->  Label name in the switch statement. 
 *                              (If the character after % is not a valid specifier, the default block handles it as a "fail-safe.)
 *  '_putchar('%')'         ->  Print the literal symbol '%'
 *  '_putchar(format[*i])'  ->  Print the unknown format specifier itself after the format string '%'
 *                              eg. [printed_chars = printed_chars + print_char(list);]
 *  'print_char += 2'       ->  This will add the value 2 to 'print_char' since it has printed the symbol and the unknown character.
 */
}
return (printed_chars); /* Returns total number of characters printed */
}
```
</details>

## print_functions.c:

- Contains individual functions for printing different types
- Each function `print_char` `print_string` `print_percent` handles a specific format specifier (c, s, %)
- These functions use a helper function `_putchar` to write characters to the standard output,\
    and they support formatted output similar to the behavior of the `printf` function in C.

<details>
    <summary>Function Explanation</summary>

```c#
int print_char(va_list types)   /*  'types' -> A list containing the character to print.*/
{
char c = va_arg(types, int);    /*  Retrieves the next argument from types as an int 
                                 *  characters are converted to int when passed through va_list
                                 */
return (_putchar(c));           /*  Calls _putchar to print the character c
                                 *  characters are converted to int when passed through va_list
                                 */
}


int print_string(va_list types)     /* 'va_list types' -> A list containing the string to print.*/
{
int length = 0;                     /* Records the number of characters printed */
char *str = va_arg(types, char*);   /* Retrieves the next argument from 'types' as a char* (string pointer). */

if (!str)
str = "(null)";     /* If the 'str' pointer is NULL (not pointing to a valid memory location)
                     * Then set it to the location of string "(null)"
                     * This command acts as a "fall-back" (fail safe) for the function to not crash
                     */

while (str[length] != '\0')
{
_putchar(str[length]);
length++;
}
/*  'while (str[length] != '\0')'   -> 'While the character at 'str[length]' is not the null terminator ('\0'), continue executing the loop.
 *
 *  '_putchar'                      -> print each character of the string 'str'
                                        eg. str = "Hello"
                                        eg. length =    H - 0
                                                        e - 1
                                                        l - 2
                                                        l - 3
                                                        o - 4
                                                        * - \0 (stops printing)
 *
 *  'length++'                      ->  is being used to to move across the while loop after each execution.
 *                                      moves to the next character through the string. 
 */

return (length);
}


int print_percent(void) /* 'void' -> Prints the '%' character itself. This is used when the format string contains %% */
{
_putchar('%');  /* Prints the '%' symbol using _putchar */
return (1);     /* Returns 1, indicating one character printed. */
}
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
int print_int(va_list types)    /* 'va_list types' -> A list containing the integer to print. */
{
    int n = va_arg(types, int); /*  Retrieves the next argument from types as an int 
                                 *  characters are converted to int when passed through va_list
                                 */
    return (print_digit(n));    /* Calls '_print_digit' to print the character n
                                 *  characters are converted to int when passed through va_list
                                 */
}


int print_digit(int n)          /* 'int d' -> The digit to print as an integer (0-9) */
{
    int count = 0;              /*  Variable to count the number of characters printed */
    unsigned int digit;         /* Declare an unsigned integer to handle the number's absolute value (That being a positive value and zero) */

    if (n < 0)                  /*  Checks if the number is negative */
    {
        _putchar('-');          /*  Prints the negative sign */
        count++;                /*  Increment count since the negative sign counts as one character 
                                 *  This is used for when there is more than 1 number (eg. 12345)
                                 *  
                                 */
        digit = -n;              /* Converts the negative number to positive (two negatives make a positive) */
    }
    else
        digit = n;              /*  If the number is not negative, use the number directly */

    if (digit / 10)             /*  Checks if the number has more than one digit (i.e., it is greater than 9)
                                 *  
                                 */
        count += print_digit(digit / 10);  /* Recursively calls print_digit to print the higher digits (if any) 
        * purpose of this recursion is to process and print each digit of the number from the most significant (leftmost) digit to the least significant (rightmost) digit 
        *
        */

    _putchar((digit % 10) + '0');  /* Prints the current digit (the ones place)
    * % operator (modulus) computes the remainder when digit is divided by 10. This operation extracts the last digit (ones place) of the number. So working in reverse to the previous command. 
    *
    * '+ '0'' -> Adding '0' to a number between 0 and 9 converts it into its corresponding ASCII value (character).
    */
    count++;            /* Increments the count for this digit */

    return (count);     /* Returns the total number of characters printed */
}

```
</details>


