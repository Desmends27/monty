#include "monty.h"
/**
 * excute - calls the command to be excuted
 * @opcode - string of the op command
 */

int execute (stack_t **stack, unsigned int line_num, FILE *fp)
{
	int i = 0;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"nop", nop},
		{"NULL", NULL}
	};
	var.opcode = strtok(var.line, DELIM);
	var.arg = strtok(NULL, DELIM);
	while (ops[i].opcode && var.opcode)
	{
		if (strcmp(var.opcode, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_num);
			return (0);
		}
		i++;
	}
	if ( var.opcode && ops[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, var.line);
		fclose(fp);
		exit(EXIT_FAILURE);
		return (1);
	}
	return (1);
}

