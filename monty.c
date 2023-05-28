#include "monty.h"
#include <stdio.h>

monty_t mont = {NULL, NULL, NULL, 0};
/**
 * process_file - Function to process the contents of a file
 * @filename: The name of the file to process
 * Returns: None
 */
void process_file(const char *filename)
{
	char buffer[BUFFER_SIZE];
	FILE *file;
	size_t size = BUFFER_SIZE;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	file = fopen(filename, "r");
	mont.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		read_line = fread(buffer, sizeof(char), size, file);
		mont.content = buffer;
		line_number++;

		if (read_line > 0)
		{
			execute(buffer, &stack, line_number, file);
		}
	}

	free_stack(stack);
	fclose(file);
}

/**
 * main - validates the command-line arguments, extracts and calls a function
 * @argc: Number of command-line arguments
 * @argv: Array of command-line
 *
 * Returns: 0 on successful execution
 */
int main(int argc, char *argv[])
{
	const char *filename;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = argv[1];
	process_file(filename);

	return (0);
}
