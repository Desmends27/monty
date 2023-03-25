#include "monty.h"
/**
 * nop - does nothing
 * @struct: pointer to top of struct
 * @line_number: line number
 * 
 */
void nop(__attribute__((unused))stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    return;
}