#include "monty.h"
/**
 * main - entry point
 * @ac: number of cmd line arguements
 * @av: command line arguements
 * Return: 0 for success
 */
globalFD ob1 = {NULL};
int main(int ac, char **av)
{
	char buffer[2000];
	char sizer[300] = "";
	char *i = sizer;
	int l = 1;
	stack_t *myStack = NULL;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	ob1.fd = fopen(av[1], "r");
	if (!ob1.fd)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, 2000, ob1.fd))
	{
		i = strtok(buffer, " \t");
		op(&myStack, l, i)(&myStack, l);
	}
	freeStack(&myStack);
	fclose(ob1.fd);
	return (EXIT_SUCCESS);
}
/**
 * op - calls the correct operation
 * @stack: stack
 * @line: line number
 * @key: opcode
 *
 * Return: Pointer to respective function
 */
void (*op(stack_t **stack, int line, char *key))(stack_t **, unsigned int)
{
	int x = 0;
	unsigned int i = 0;
	instruction_t opMatch[] = {
		{"push", stackPush},
		{"pall", stackPall},
		{"pint", _pint},
		{"pop", pop},
		{"swap", _swapper},
		{"add", _adder},
		{"nop", _nop },
		{NULL, NULL}
	};

	for (; opMatch[x].opcode; x++)
	{
		for (; i <= strlen(key); i++)
		{
			if (key[i] == '\n')
				key[i] = '\0';
		}
		if (strcmp(opMatch[x].opcode, key) == 0)
			return (opMatch[x].f);
	}
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line, key);
	freeStack(stack);
	fclose(ob1.fd);
	exit(EXIT_FAILURE);
}
/**
 * freeStack - frees the stack
 * @stack: stack
 */
void freeStack(stack_t **stack)
{
	stack_t *ii;

	while (*stack)
	{
		ii = *stack;
		*stack = (*stack)->next;
		free(ii);
	}
}
