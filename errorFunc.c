#include "monty.h"
/**
 * errormsg - function to display push error
 * @stack01: stack that is passed
 * @lineOfArg: line of the argument
 *
 * Return: No return type
 */
void errormsg(stack_t **stack01, unsigned int lineOfArg)
{
	dprintf(STDERR_FILENO, "L%u: usage: push integer\n", lineOfArg);
	freeStack(stack01);
	exit(EXIT_FAILURE);
}
