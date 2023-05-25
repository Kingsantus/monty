#include "monty.h"

/*
 * add_node - adds a new node to the beginning of a stack
 * @head: Pointer to the head of the stack.
 * @n: Value to be stored in the new node.
 *
 * Returns: Pointer to the updated head of the stack.
 */

stack_t *add_node(stack_t **head, unsigned int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));

	if (!new)
		return (NULL);

	if (!*head)
	{
		new->n = n;
		new->next = NULL;
		new->prev = NULL;
		*head = new;
		return (*head);
	}

	(*head)->prev = new;
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head = new;
	return (*head);
}

/*
 * free_node - Frees the memory allocated in a stack
 * @head: Pointer to the head of the stack.
 *
 * Returns: None.
 */

void free_node(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
