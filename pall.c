#include "monty.h"
/**
 * pall: does something 
 * 
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
    stack_t *temp = *stack;
    while (temp != NULL)
    {
        fprintf(stdout,"%d\n", temp->n);
        temp = temp->next;
    }
}