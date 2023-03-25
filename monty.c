#include "monty.h"
/**
 * main - the monty interpreter
 * @argc: argument counter
 * @argv: argument vector
 * Return: 0 on success, 1 on error
 */
var_s var;

int main(int argc, char **argv)
{
	char *line;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int line_number = 1;
	char *opcode;
	
	void (*fnc)(stack_t **stack, unsigned int number) = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while(read_line > 0)
	{
		line = NULL;
		read_line = getline(&line, &size, file);
		var.line = line;
		if (read_line > 0)
		{
			opcode = strtok(line, DELIM);
			var.arg = strtok(NULL, DELIM);
			fnc = get_op(opcode);
			if (fnc == NULL)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n",line_number, opcode);
				exit(EXIT_FAILURE);
			}
			fnc(&stack, line_number);
		}
		free(line);
	}
	fclose(file);
	return (0);
}