#include "monty.h"
/**
 * excute - calls the command to be excuted
 * @opcode - string of the op command
 */
void (*get_op(char *opcode))(stack_t **stack, unsigned int line_num)
{
	int i;

	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"nop", nop},
		{"NULL", NULL}
	};
	for (i = 0; i < 3; i++)
	{
		if (strcmp(opcode, ops[i].opcode) == 0)
		{
			return (ops[i].f);
		}
	}
	return (NULL);
}

