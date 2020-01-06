#include "monty.h"
/**
 * _mod - mods top 2 elements
 * @stack0: stack
 * @lnum: line number
 *
 * Return: No return type
 */
void _mod(stack_t **stack0, unsigned int lnum)
{
	stack_t *i;

	if (!((*stack0)->next && *stack0))
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n", lnum);
		freeStack(stack0);
		exit(EXIT_FAILURE);
	}
	(*stack0)->next->n %= (*stack0)->n;
	i = (*stack0);
	(*stack0) = (*stack0)->next;
	(*stack0)->prev = NULL;

	free(i);
}
