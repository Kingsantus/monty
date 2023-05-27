#include "monty.h"

/**
 * execute - Executes instructions based on the line
 * @content: Pointer to the content of the file
 * @stack: Pointer to the stack structure
 * @line_number: Line number of the current instruction
 * @file: Pointer to the file being executed
 *
 * Return: 0 if successful, 1 otherwise
 */
int execute(char *content, stack_t **stack, unsigned int line_number, FILE *file)
{
	instruction_t opst[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"queue", _queue},
		{"stack", _stack},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, "\n\t");
	if (op && op[0] == '#')
		return (0);
	mont.arg = strtok(NULL, "\n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}
