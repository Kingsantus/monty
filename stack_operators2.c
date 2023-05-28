#include "monty.h"

/**
 * _swap - Swaps the values of the top two elements in a stack
 * @head: Pointer to the stack data
 * @line_number: where the function is called
 */
void _swap(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(mont.file);
		free(mont.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}

/**
 * _add - Adds the top two elements of a stack
 * @head: Pointer to the stack
 * @line_number: where the function is called
 */
void _add(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(mont.file);
		free(mont.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n + h->next->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}

/**
 * _nop - No operation function
 * @head: Pointer to the stack not used
 * @line_number - where the function is called not used
 */
void _nop(stack_t **head, unsigned int line_number)
{
	(void) line_number;
	(void) head;
}
