#include "monty.h"
/**
 *
 *
 */
FILE *fd = NULL;
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

	fd = fopen(av[1], "r");
	if (!fd)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while(fgets(buffer, 2000, fd))
	{
		i = strtok(buffer, " \t");
		printf("Strtok works\n");
		opcall(&myStack, l, i)(&myStack, l);

	}
	freeStack(&myStack);
	return (EXIT_SUCCESS);

}
/**
 *
 *
 */
void (*opcall(stack_t **stack, int line, char *keyword))(stack_t **, unsigned int)
{	
	int x = 0;
	unsigned int i = 0;
	instruction_t opMatch[] =
	{
		{"push", stackPush},
		{"pall", stackPall},
		{NULL, NULL}
	};
	printf("Before for\n");
	for (;opMatch[x].opcode; x++)
	{
		for (; i <= strlen(keyword); i++)
		{
			printf("Checking for new line\n");
			if (keyword[i] == '\n') keyword[i] = '\0';
		}
		printf("%s", keyword);
		printf("Exit new line check\n");
		if (strcmp(opMatch[x].opcode, keyword) == 0) 
			printf("Confirm match %s\n", keyword);
		
		return (opMatch[x].f);
	}
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line, keyword);
	freeStack(stack);
	fclose(fd);
	exit(EXIT_FAILURE);
}
/**
 *
 *
 */
void freeStack(stack_t **stack)
{
	stack_t *i;

	for(; *stack; i = *stack, *stack = (*stack)->next) free(i);
}
