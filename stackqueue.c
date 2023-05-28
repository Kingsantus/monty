#include "monty.h"

/**
 * _stack - Sets the data structure type to stack
 * @head: Pointer to the stack not used
 * @line_number: where the function is called not used
 */
void _stack(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
	mont.lifi = 0;
}

/**
 * _queue - Sets the data structure type to queue
 * @head: Pointer to the stack not used
 * @line_number: where the function is called not used
 */
void _queue(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
	mont.lifi = 1;
}

/**
 * addqueue - Adds a new node to the end of a queue
 * @head: Pointer to the head of list
 * @n: Value to be stored in the new node
 */
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
