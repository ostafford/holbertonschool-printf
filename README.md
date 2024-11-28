# _printf

### main.h:

- Contains all function prototypes
- Includes necessary header files
- Has include guards to prevent multiple inclusion

<details>
  <summary>Click to expand</summary>
  ```c
int _printf(const char *format, ...);
/* 
 * Custom implementation of the `printf` function.
 * - Takes a format string (`format`) and additional arguments (variable arguments: `...`).
 * - Parses the format string and handles various format specifiers to print output.
 * - Returns the number of characters printed.
 */

int handle_print(const char *format, int *i, va_list list);
/* 
 * Helper function for `_printf` to handle the actual printing of characters based on format specifiers.
 * - `format`: The format string being processed.
 * - `i`: Pointer to the current index in the format string.
 * - `list`: A `va_list` holding the variable arguments.
 * - Returns the number of characters printed for the current format specifier.
 */

int print_char(va_list types);
/* 
 * Function to handle the `%c` format specifier in `_printf`.
 * - `types`: A `va_list` holding the variable arguments.
 * - Retrieves and prints a single character.
 * - Returns the number of characters printed (always 1 for `%c`).
 */

int print_string(va_list types);
/* 
 * Function to handle the `%s` format specifier in `_printf`.
 * - `types`: A `va_list` holding the variable arguments.
 * - Retrieves and prints a string.
 * - Returns the number of characters printed.
 */

int print_percent(void);
/* 
 * Function to handle the `%%` format specifier in `_printf`.
 * - Prints a single `%` character.
 * - Returns the number of characters printed (always 1 for `%%`).
 */

int print_int(va_list types);
/* 
 * Function to handle the `%d` and `%i` format specifiers in `_printf`.
 * - `types`: A `va_list` holding the variable arguments.
 * - Retrieves and prints an integer.
 * - Returns the number of characters printed.
 */

int print_digit(int d);
/* 
 * Helper function to print a single digit.
 * - `d`: The digit to print (0–9).
 * - Prints the digit and returns the number of characters printed (always 1).
 */

</details>


### _putchar.c:

- Contains the implementation of _putchar function
- Uses write system call to output characters

### _printf.c:

- Contains the main _printf function
- Handles the basic parsing of the format string
- Delegates specific format specifiers to handle_print

### handle_print.c:

- Contains the logic for handling different format specifiers
- Uses a switch statement to route to appropriate print functions

### print_functions.c:

- Contains individual functions for printing different types
- Each function handles a specific format specifier (c, s, %)

### print_numbers.c:

- print_int(): Gets an integer argument from va_list and passes it to print_number
- print_number(): Recursively prints an integer, handling:
    - Negative numbers (prints minus sign and converts to positive)
    - Multi-digit numbers (uses recursion to print each digit)
    - Returns count of characters printed


