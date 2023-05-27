#include "monty.h"

/**
 * _realloc - Reallocates memory for a character array
 * @ptr: Pointer to the original memory block
 * @old_size: Size of the original memory block
 * @new_size: Size of the new memory block.
 *
 * Return: Pointer to the reallocated memory block
 */
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr = malloc(new_size);

	if (new_ptr != NULL)
	{
		if (ptr != NULL)
		{
			memcpy(new_ptr, ptr, old_size);
			free(ptr);
		}
	}

	return new_ptr;
}

/**
 * getstdin - Reads input from the standard input
 * @lineptr: Pointer to the buffer to store the input
 * @file: File descriptor
 *
 * Return: The number of characters read
 */
ssize_t getstdin(char **lineptr, int file)
{
	char *buffer = NULL;
	size_t bufsize = 0;

	ssize_t char_read = getline(&buffer, &bufsize, stdin);

	if (chars_read != 2)
	{
		*lineptr = buffer;
	}
	else
	{
		*lineptr = NULL;
	}

	return chars_read;
}

/**
 * clean_line - Removes leading and trailing whitespace
 * @line_number: Pointer to the string
 *
 * Return: Pointer to the cleaned string
 */
char *clean_line(char *line_number)
{
	while (isspace(*line_number))
	{
		line_number++;
	}

	char *end = line_number;
	while (*end != '\0')
	{
		end++;
	}
	end--;

	while (end > line_number && isspace(*end))
	{
		*end = '\0';
		end--;
	}

	return line_number;
}
