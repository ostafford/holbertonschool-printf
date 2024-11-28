# _printf steps

Step 1: 

# print_char Steps

prototype 
`int print_char(char c) {   return (write(1, &c, 1));  }`

Step 1: `write()` writes the data once it is called

Step 2: value `1` is the `stdout` descriptor which is the standard output(terminal).

Step 3: `pointer(&c)` address of character to be written to specifier `%c`

Step 4: byte value `1`. how many bytes does a character take? 1.


# print_string

Step 1: `count` record how many characters there are

Step 2: `!str` if str is NOT a string print NULL.
        This allows a fail safe for the pointer of the string.

Step 3: `*str` once the fail safe has passed we then start from the pointer.

Step 4: `count +=` this line allows the program to write each character in the string to stdout (terminal)
                only 1 character at a time.

Step 5: `return` once all characters are printed. return the total amount value of characters printed.
