#include "monty.h"
#include <ctype.h>
/**
 *
 *
 *
 */
void stackPush(stack_t **new, unsigned int lineNo)
{
	int number;
	char emptySizer[300] = "";
	char *arg_ch = emptySizer;
	printf("Enters push\n");
	arg_ch = strtok(NULL, " \t");
	printf("After tokenizing: %s\n", arg_ch);
	if (!arg_ch)
	{	printf("Checking error\n");
		errormsg(new, lineNo);
	}
	printf("Checking error\n");
	if (arg_ch[0] == '\n')
		errormsg(new, lineNo);
	printf("Checking error\n");
	number = atoi(arg_ch);
//	if (_isDigit(arg_ch) == 0)
//		errormsg(new, lineNo);
	printf("Sending control to LL adder function\n");
	LL_adder(new, number);
}
/**
 *
 *
 *
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
 *
 *
 *
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
