#include "monty.h"
/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to head of stack
 * @line_number: incase of errors
 *
 *
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack is empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
