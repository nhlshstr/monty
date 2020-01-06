#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
/**
 * struct fileStuff - file pointing structure
 * @fd: file pointer
 */
typedef struct fileStuff
{
	FILE *fd;
} globalFD;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
void (*op(stack_t **stack, int line, char *key))(stack_t **, unsigned int);
void _pint(stack_t **stacks, unsigned int lineNo);
void freeStack(stack_t **stack);
void stackPush(stack_t **new, unsigned int lineNo);
void LL_adder(stack_t **stacker, int ar);
void errormsg(stack_t **stack01, unsigned int lineOfArg);
int _isDigit(char *arg);
void stackPall(stack_t **printedStack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void _swapper(stack_t **sstack, unsigned int lNo);
void _adder(stack_t **stack0, unsigned int lnum);
void _nop(stack_t **stack, unsigned int lineNum);
#endif /* MONTY_H */
