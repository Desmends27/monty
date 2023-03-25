#define _GNU_SOURCE
#ifndef MONTY_H
#define MONTY_H
#define DELIM " \t\r\n\a"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

int execute (stack_t **stack, unsigned int line_num, FILE *fp);
/**
 * var_t - vars, functions used through out program
 * @number: number argument
 * @opcode: code obtained
 * @line: line read from file
 * Description: stores global vars in the program
 * 
 */
typedef struct var_s
{
	int number;
	char *opcode;
	char *arg;
	FILE *fp;
	char *line;
} var_t;
extern var_t var;
#endif /*MONTY_H*/
