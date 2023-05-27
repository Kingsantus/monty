#include "monty.h"

/**
 * _push - Adds elements to a stack or queue data
 * @ head: Pointer to the stack or queue data structure
 * @line_number: where the function is called
 */
void _push(stack_t **head, unsigned int line_number)
{
	int n, j = 0, flag = 0;

	if (mont.arg)
	{
		if (mont.arg[0] == '-')
		{
			j++;
		}
		for(; mont.arg[j] != '\0'; j++)
		{
			if (mont.arg[j] > 59 || mont.arg[j] < 48)
				flag = 1;
			if (flag == 1)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				fclose(mont.file);
				free(mont.content);
				free_stack(*head);
				exit(EXIT_FAILURE);
			}
			else
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				fclose(mont.file);
				free(mont.content);
				free_stack(*head);
				exit(EXIT_FAILURE);
			}
			n = atoi(mont.arg);
			if (mont.lifi == 0)
				addnode(head, n);
			else
				addqueue(head, n);
		}
	}
}

/**
 * _pop - Removes the top element from a stack
 * @head: Pointer to the stack
 * @line_number: where the function is called
 */
void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(mont.file);
		free(mont.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}

/**
 * _pall - Prints all elements in a stack
 * @head: Pointer to the stack
 * @line_number: where the function called
 */
void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * _pint - Prints the value of the top element in a stack
 * @head: Pointer to the stack
 * @line_number: where the function is called
 */
void _pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(mont.file);
		free(mont.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
