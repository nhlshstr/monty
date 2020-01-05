#include "monty.h"
#include <ctype.h>
/**
 * stackPush - Gets the arguement in int form
 * @new: stack
 * @lineNo: Line Number
 *
 * Return: No return type
 */
void stackPush(stack_t **new, unsigned int lineNo)
{
	int number;
	char emptySizer[300] = "";
	char *arg_ch = emptySizer;

	arg_ch = strtok(NULL, " \t");
	if (!arg_ch)
	{
		errormsg(new, lineNo);
	}
	if (arg_ch[0] == '\n')
		errormsg(new, lineNo);
	number = atoi(arg_ch);
	if (!_isDigit(arg_ch) == 0)
		errormsg(new, lineNo);
	LL_adder(new, number);
}
/**
 * LL_adder - adds the arguement to list
 * @stacker: Double pointer to stack
 * @ar: arguement passed
 *
 * Return: No return type
 */
void LL_adder(stack_t **stacker, int ar)
{
	stack_t *temp;

	temp = malloc(sizeof(size_t));
	if (temp)
	{
		temp->n = ar;
		temp->next = *stacker;
		temp->prev = NULL;
		if (*stacker)
			((*stacker)->prev = temp);
		*stacker = temp;
		return;
	}
	dprintf(STDERR_FILENO, "Error: malloc failed\n");
	freeStack(stacker);
	exit(EXIT_FAILURE);

}
/**
 * stackPall - lists all the nodes
 * @printedStack: stack to be printed
 * @line_number: line number
 *
 * Return: No return
 */
void stackPall(stack_t **printedStack, unsigned int line_number)
{
	stack_t *initial;

	(void) line_number;

	for (initial = *printedStack; initial; initial = initial->next)
	{
		printf("%d\n", initial->n);
	}
}
