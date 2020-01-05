#include "monty.h"

/**
 *
 *
 *
 */
void pop(stack_t **stack, unsigned int line_number)
{

	stack_t *temp, *nexTemp;

	if(stack == NULL)
	{
		dprintf(STDERR_FILENO, "L<%u>: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	nexTemp = temp->next;

	if(nexTemp != NULL)
	{
		nexTemp->prev = NULL;
		free(temp);
		*stack = nexTemp;
	}

}
