#include "monty.h"
/**
 *
 *
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
