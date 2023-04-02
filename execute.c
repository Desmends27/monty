#include "monty.h"
/**
 * execute - calls the command to be excuted
 * @stack: head of the stack
 * @line_num: current line number
 * @fp: file opened
 * Return:1 on success, 0 on error
 */

int execute(stack_t **stack, unsigned int line_num, FILE *fp)
{
	int i = 0;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"swap", swap},
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
	if (var.opcode && ops[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, var.line);
		fclose(fp);
		free_stack(stack);
		exit(EXIT_FAILURE);
		return (1);
	}
	return (1);
}

