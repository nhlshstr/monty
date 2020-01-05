#include "monty.h"
/**
 * _isDigit - Checks if number is a digit
 * @arg: Argument in string form
 *
 * Return: Returns Boolean 1 or 2
 */
int _isDigit(char *arg)
{
	int i = 0;

	for (; arg[i]; i++)
	{
		if (!(arg[i] >= '0' && arg[i] <= '9'))
			return (0);
	}

	return (1);
}
