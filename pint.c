#include "monty.h"
/**
 * _pint - prints element at top of stack
 * @stacks: stack passed to the function
 * @lineNo: Line Number
 */
void _pint(stack_t **stacks, unsigned int lineNo)
{
	if (*stacks)
		printf("%d\n", (*stacks)->n);
	else
	{
		dprintf(STDERR_FILENO, "L%u: Can't print, stack empty\n", lineNo);
		freeStack(stacks);
		exit(EXIT_FAILURE);
	}
}
