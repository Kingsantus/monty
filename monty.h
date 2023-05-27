#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

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

/**
 * monty_s - representing the state of the interpreter
 * @arg: Pointer to a char, representing the argument
 * @file: Pointer to a FILE, representing the file
 * @content: Pointer to a char
 * lifi: Integer representing the mode (0 for stack, 1 for queue)
 */
typedef struct monty_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  monty_t;
extern monty_t mont;

/* prototype used for execution */
void process_file(const char* filename);
void _push(stack_t **head, unsigned int number);
void _pall(stack_t **head, unsigned int number);
void _pint(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int line_number, FILE *file);
void free_stack(stack_t *head);
void _pop(stack_t **head, unsigned int line_number);
void _swap(stack_t **head, unsigned int line_number);
void _add(stack_t **head, unsigned int line_number);
void _nop(stack_t **head, unsigned int line_number);
void _sub(stack_t **head, unsigned int line_number);
void _div(stack_t **head, unsigned int line_number);
void _mul(stack_t **head, unsigned int line_number);
void _mod(stack_t **head, unsigned int line_number);
void _pchar(stack_t **head, unsigned int line_number);
void _pstr(stack_t **head, unsigned int line_number);
void _rotl(stack_t **head, unsigned int line_number);
void _rotr(stack_t **head, __attribute__((unused)) unsigned int line_number);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void _queue(stack_t **head, unsigned int line_number);
void _stack(stack_t **head, unsigned int line_number);

#endif
