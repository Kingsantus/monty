#include "monty.h"

/**
 * addnode - Adds a new node to the beginning of a stack
 * @head: Pointer to the head of a list
 * n: Value to be stored in the new node
 */
void addnode(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("ERROR\n");
		exit(0);
	}
	if (aux)
	{
		aux->prev = new_node;
	}
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

/**
 * free_stack - Frees the memory allocated for a list
 * @head: Pointer to the head of a list
 */
void free_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
