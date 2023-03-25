#include "monty.h"
/**
 * pop - removes element from stack
 * @stack: stack head
 * @line_number: line number
 *  
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *h;
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        fclose(var.fp);
        free(var.line);
        exit(EXIT_FAILURE);
    }
    h = *stack;
    *stack = h->next;
    free(h);
}