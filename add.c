#include "monty.h"
/**
 * add - adds the top elements on the stack
 * @stack: stack head
 * @line_number: line_number 
 * 
 */
void add(stack_t **stack, unsigned int line_number)
{
    stack_t *h = *stack;
    int sum, len = 0;
    while (h)
	{
		h = h->next;
		len++;
	}

    if (len > 2)
    {
		fclose(var.fp);
		free(var.line);
		exit(EXIT_FAILURE); 
    }
    fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
    sum = h->n + (h->next)->n;
    h->next->n = sum;
    *stack = h->next;
    free(h);  
}