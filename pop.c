#include "monty.h"

/**
 * pop:- the function that will delete a stack from the top.
 * @stack:-this is the head of the stack
 * @line_number: the integer data within the stack plate or node.
 */
void pop(stack_t **stack, unsigned int line_number)
{

	stack_t *temp, *nexTemp;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	nexTemp = temp->next;

	if (nexTemp != NULL)
	{
		nexTemp->prev = NULL;

	}
	free(temp);
	*stack = nexTemp;
}
