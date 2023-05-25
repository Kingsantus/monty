#include "monty.h"
int indicator = 0;

/**
 * main - input for monty program
 * @ac: int num of arguments
 * @av: opcode file
 * Return: 0 or error if ac not = 2
 */
int main(int ac, char **av)
{
	stack_t *stack;

	stack = NULL;
	if (ac != 2)
	{
		printf("USAGE: monty file \n");
		error_exit(&stack);
	}
	read_file(av[1], &stack);
	free_node(stack);
	return (0);
}
