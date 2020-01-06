# Monty project

This project is creating a complied verison to take in bytecodes given to us to work with-in our Monty program

## Getting Started

### Prerequistes

The prerequisites to create this understand FILE I/O, stack & queue data structure
in C.

### Functions

| Name | Description |
|:-----:|:------:|
| freeStack | |
| _pint | prints the value at the top of the stack. |
| stackPush | pushes an element to the stack. |
| LL_adder | |
| errormsg | This helps push error messages to display. |
| _isDigit | This function checks if the number is a digit. |
| stackPall | prints all the values on the stack, starting from the top of the stack.|
| pop | removes the top element of the stack. |
| _swapper | swaps the top two elements of the stack. |
| op | calls the correct operation. |
| _adder | adds top 2 elements together. |


### Error message

| Name | Description |
|:----:| :----------:|
| opcode unknown | L<line_number>: unknown instruction <opcode> |
| USAGE: monty file | if the user does not give any file or more than one argument to your program |
| Error: Can't open file <file> | If, for any reason, it’s not possible to open the file, print the error message |
| L<line_number>: unknown instruction <opcode> | f the file contains an invalid instruction |
| Error: malloc failed | If you can’t malloc anymore |
| L<line_number>: usage: push integer | if <int> is not an integer or if there is no argument given to push |
| L<line_number>: can't pint, stack empty | If the stack is empty but pint is still in the .m file |
| L<line_number>: can't pop an empty stack | If the stack is empty but pop is still in the .m file |
| L<line_number>: can't swap, stack too short | If the stack contains less than two elements for _swappers |
| L<line_number>: can't add, stack too short | If the stack contains less than two elements for add function |

### Compilation

With the command below, this will be used to compile our monty python project
```
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

## Running the tests
Test_1
```
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
```
Test_2
```
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
```
## Flowchart

## Contributing

### Authors
Nehal Shastri and Kenneth Fernandez.