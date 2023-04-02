#include "monty.h"
/**
 * swap - swap head and head->next
 * @stack: head of stack
 * @line_number: error handling
 *
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	int len = 0, temp;

	h = *stack;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(var.fp);
		free(var.line);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	temp = h->n;
	h->n = h->next->n;
	h->next->n = temp;

}
