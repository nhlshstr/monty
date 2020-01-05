#include "monty.h"
/**
 *
 *
 */
void errormsg(stack_t **stack01, unsigned int lineOfArg)
{
	dprintf(STDERR_FILENO, "L%u: usage: push integer\n", lineOfArg);
	freeStack(stack01);
	exit(EXIT_FAILURE);
}
