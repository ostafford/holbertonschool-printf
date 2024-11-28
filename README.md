# _printf

### main.h:

- Contains all function prototypes
- Includes necessary header files
- Has include guards to prevent multiple inclusion

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

