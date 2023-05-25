#include "monty.h"

/**
 * error_exit - frees the stack & exits due to error
 * @stack: pointer to the head
 */
void error_exit(stack_t **stack)
{
	if (*stack)
		free_node(*stack);
	exit(EXIT_FAILURE);
}

/*
 * _stack = Resets the indicator variable to stack
 * @stack: Pointer to the stack (unused).
 * @line_number: Line number of the instruction (unused).
 * Returns: None.
*/
void _stack(__attribute__ ((unused)) stack_t **stack,
	    __attribute__ ((unused)) unsigned int line_number)
{
	indicator = 0;
}
