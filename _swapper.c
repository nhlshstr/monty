#include "monty.h"
/**
 * _swapper - function to swap top 2 elements
 * @sstack: pointer to stack
 * @lNo: Line number
 *
 * Return: No return (void)
 */

void _swapper(stack_t **sstack, unsigned int lNo)
{
	int i = 0;

	if (!((*sstack)->next && *sstack))
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", lNo);
		freeStack(sstack);
		exit(EXIT_FAILURE);
	}

	i = (*sstack)->n;
	(*sstack)->n = (*sstack)->next->n;
	(*sstack)->next->n = i;
}
