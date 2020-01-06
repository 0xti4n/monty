#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO Holberton project
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
* for stack, queues, LIFO, FIFO Holberton project
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
int n;
void mod_fun(stack_t **stack, unsigned int line_number);
void div_fun(stack_t **stack, unsigned int line_number);
void mul_fun(stack_t **stack, unsigned int line_number);
void sub_fun(stack_t **stack, unsigned int line_number);
void nop_fun(stack_t **stack, unsigned int line_number);
void add_fun(stack_t **stack, unsigned int line_number);
void swap_fun(stack_t **stack, unsigned int line_number);
void getlines(stack_t **head, char **av);
void pop_fun(stack_t **stack, unsigned int line_number);
char **tokenize(char *line);
void verification(stack_t **head, char *line, int n_line, FILE *fd);
void add_stack(stack_t **head, unsigned int line_number);
void print_all(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *head);
void pint_fun(stack_t **stack, unsigned int line_number);
#endif
