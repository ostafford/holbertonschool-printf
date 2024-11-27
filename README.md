# _printf steps

Step 1: `va_list args;` this will check for multiple arguments that are passed through the function (if any)

Step 2: `int count` will record the number of characters that are printed. 
**(think of it as a step counter)**

Step 3: `format checker` the first `if` statement I created will check if the format of the string is EQUAL to NULL then it will through an error message up to indicate this is not a string input.

Step 4: `initializer` va_start will start going through the list of arguments

Step 5: `while` Once the code has passed the format checker it will then start going through each character of the string that is passed through the `va_start`. 
**(Imagine the while concept as a queue system where someone is going through the queue and confirming you are present.)**

Step 6: `if...else` Now that we are going through each character of the string we need to check if we have a format specifier being the `%` symbol. (eg. `*format == '%'`).
If it doesn't have the format specifier than print what the input is. 
**(Continuing off the queue system before imagine this as do you have an appointment or not if so continue if not then tell me your issue and we will book an appointment for another day)**

Steps 7: `++` Part of the if statement this operator will allow the code to move to the next character after the format specifier `%`. 

Step 8: `switch` in conjunction with the `++` operator the switch statement gives the if statement options on which case to execute depending on the character after the format specifier. 

Step 9: `else` statement in 's' case. Reason for this is to catch any errors in the 'string' case if there is any as a string would have multiple characters that may or may not pass the function. so having this error message available will help me resolve any issue or find it. 

Step 10: `special characters` last case of the switch statement will print what character is after the format specifier being the `%`. 

Step 11: `default` allows the switch statement to handle any unknown format specifiers and will print the format specifier followed by the character. This is basically a safe guard for when all other cases have been passed but has passed the format it will just print out an error message followed by what the string is. 

Step 12: `va_end` will clean up the va_list (step 1)

