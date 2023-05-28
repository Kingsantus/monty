#include "monty.h"

/**
 * _sub - Subtracts the top element the stack from the second top element
 * @head: Pointer to the head of the stack.
 * line_number: Line number of the instruction.
 * Returns: void
 */
void _sub(stack_t **head, unsigned int line_number)
{
	stack_t *aux;
	int result, count;

	aux = *head;
	for (count = 0; aux != NULL; count++)
		aux = aux->next;
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(mont.file);
		free(mont.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	result = aux->next->n - aux->n;
	aux->next->n = result;
	*head = aux->next;
	free(aux);
}

/**
 * _div - Divides the second top element of the stack by the top element
 * @head: Pointer to the head of the stack
 * @line_number: Line number of the instruction
 *
 * Return: void
 */
void _div(stack_t **head, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(mont.file);
		free(mont.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(mont.file);
		free(mont.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n / h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}

/**
 * _mul - Multiplies the second top element of the stack with the top element
 * @head: Pointer to the head of the stack
 * @line_number: Line number of the instruction
 *
 * Returns: void
 */
void _mul(stack_t **head, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(mont.file);
		free(mont.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->next->n * h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}

/**
 * _mod - Computes the modulo of the second top element by the top element
 * @head: Pointer to the head of the stack
 * @line_number: Line number of the instruction
 *
 * Returns: void
 */
void _mod(stack_t **head, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(mont.file);
		free(mont.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(mont.file);
		free(mont.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n % h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
