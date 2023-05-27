#include "monty.h"

/**
 * _pchar - Prints the character corresponding to the ASCII value
 * @head: Pointer to the head of the stack
 * @line_number: Line number of the instruction
 *
 * Returns: void
 */
void _pchar(stack_t **head, unsigned int line_number)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(mont.file);
		free(mont.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(mont.file);
		free(mont.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
        }
	printf("%c\n", h->n);
}

/**
 * _pstr - Prints the string corresponding to the ASCII values
 * @head: Pointer to the head of the stack.
 * @line_number: Line number of the instruction.
 *
 * Returns: void
 */
void _pstr(stack_t **head, unsigned int line_number)
{
	stack *h;
	(void) line_number;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <=0)
			break;
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}

/**
 * _rotl - Rotates the stack to the left, moving the top element to the bottom.
 * @head: Pointer to the head of the stack.
 * @line_number: Line number of the instruction.
 *
 * Returns: void
 */
void _rotl(stack_t **head, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}

/**
 * _rotr - Rotates the stack to the right, moving the bottom element to the top.
 * @head: Pointer to the head of the stack.
 * @line_number: Line number of the instruction.
 *
 * Returns: void
 */
void _rotr(stack_t **head, __attribute__((unused)) unsigned int line_number)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
