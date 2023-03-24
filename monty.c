#include "monty.h"
/**
 * main - calls the various functions to excute command
 * @argc: argument counter
 * @argv: file to be passsed in
 * Return: 1 on sucess, 0 on error 
 * 
 */
int number;
int main(int argc, char *argv[])
{
	char line[256];
	FILE *fp;
	char *opcode;
	char *arg;
	int line_number = 1;
	void (*fnc)(stack_t **stack, unsigned int number) = NULL;
	stack_t *stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr,"USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1],"r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((fgets(line, sizeof(line), fp)))
	{
		number = 0;
		opcode = strtok(line, DELIM);
		arg = strtok(NULL, DELIM);
		if (arg == NULL && strcmp(opcode, "push") == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		if (arg != NULL)
		{
			number = atoi(arg);
		}
		fnc = get_op(opcode);
		if (fnc == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction <opcode>", line_number);
            exit(EXIT_FAILURE);
		}
		fnc(&stack, line_number);
		line_number++;
	}
	fclose(fp);
	return (0);
}
